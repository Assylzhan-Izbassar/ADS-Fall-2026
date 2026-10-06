
#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) { // child idx
        while (i > 0) {
            int p = parent(i);

            if (heap[i] < heap[p]) {
                swap(heap[i], heap[p]);
                i = p;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) { // parent idx
        int n = heap.size();
        while (true) {
            int currIdx = i;
            int leftIdx = left(currIdx);
            int rightIdx = right(currIdx);

            if (leftIdx < n && heap[leftIdx] < heap[currIdx]) {
                currIdx = leftIdx;
            }
            if (rightIdx < n && heap[rightIdx] < heap[currIdx]) {
                currIdx = rightIdx;
            }

            if (currIdx != i) {
                swap(heap[i], heap[currIdx]);
                i = currIdx;
            } else {
                break;
            }
        }
    }
public:
    void insert(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;
        heapifyUp(i);
    }

    int extractTop() {
        if (empty()) return -1;
        int t = top();
        int tailIdx = heap.size() - 1;

        swap(heap[0], heap[tailIdx]);
        heap.pop_back();

        heapifyDown(0);

        return t;
    }

    int top() {
        if (empty()) return -1;
        return heap[0];
    }

    vector<int> heapSort() {
        vector<int> copyHeap(heap);
        vector<int> result(heap.size());

        int i = 0;
        while (!empty()) { // n
            int top = extractTop(); // log n
            result[i] = top;
            i++;
        }
        heap = copyHeap;

        return result;
    }

    int empty() {
        return heap.empty();
    }

    void print() {
        for (int x: heap) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    int a[] = {3, 5, 10, 1, 9};
    int n = sizeof(a) / sizeof(int);

    MinHeap h;

    for (int i=0; i < n; ++i) {
        h.insert(a[i]);
    }

    h.print();

    vector<int> sorted = h.heapSort();

    for (int x: sorted) {
        cout << x << " ";
    }
    cout << endl;

    sort(a, a+n); // - Quick Sort

    // cout << h.extractTop() << endl;

    // h.print();

    return 0;
}