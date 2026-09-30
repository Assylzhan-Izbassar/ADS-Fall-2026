#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; } 

    void heapifyUp(int i) { // child O(log N)
        while (i > 0) {
            int pIdx = parent(i);

            if (heap[i] < heap[pIdx]) {
                swap(heap[i], heap[pIdx]);
                i = pIdx;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int i) { // parent
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
                swap(heap[currIdx], heap[i]);
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

        int fIdx = 0, lIdx = heap.size() - 1;
        swap(heap[fIdx], heap[lIdx]);

        heap.pop_back();

        heapifyDown(fIdx);

        return t;
    }

    int top() {
        if (empty()) return -1;
        return heap[0];
    }

    bool empty() {
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

    int a[] = {10, 7, 8, 1, 5, 9};
    int n = sizeof(a) / sizeof(int);

    MinHeap h;

    for (int i=0; i < n; ++i) {
        h.insert(a[i]);
    }

    h.print();

    cout << h.extractTop() << endl;

    h.print();

    return 0;
}