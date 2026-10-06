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

    void heapifyUp (int i) {
        while (i > 0) {
            int pIdx = parent(i);

            if (heap[pIdx] > heap[i]) { // direction
                swap(heap[pIdx], heap[i]);
                i = pIdx;
            } else {
                break;
            }
        }
    }

    void heapifyDown (int i) { // - parent idx
        while (true) {
            int curr = i;
            int lIdx = left(i);
            int rIdx = right(i);

            if (lIdx < heap.size() && heap[lIdx] < heap[curr]) { // direction
                curr = lIdx;
            }
            if (rIdx < heap.size() && heap[rIdx] < heap[curr]) { // direction
                curr = rIdx;
            }

            if (curr != i) {
                swap(heap[curr], heap[i]);
                i = curr;
            } else {
                break;
            }
        }
    }
public:
    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }

    int extractTop() {
        if (empty()) { return -1; }
        int top = this->top();
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
        return top;
    }

    void heapSort() {
        vector<int> copyHeap(heap);

        while (!empty()) {
            cout << extractTop() << " ";
        }
        cout << endl;

        heap = copyHeap;
    }

    int top() {
        return heap.size() > 0 ? heap[0] : -1;
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
    int a[] = {4, 5, 9, 6, 1, 10, 15};
    int n = sizeof(a) / sizeof(int);

    MinHeap h;

    for (int i=0; i < n; ++i) {
        h.push(a[i]);
    }

    h.print();

    // cout << h.top() << endl;
    
    h.heapSort();

    sort(a, a+n); // 
    
    // cout << h.extractTop() << endl;
    
    return 0;
}