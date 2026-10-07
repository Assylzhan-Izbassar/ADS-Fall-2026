#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int cnt = 0;

int lomutoPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j=low; j < high; ++j) {
        cnt++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    
    return i+1;
}

int hoarePartition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {
        cnt++;
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) return j;

        swap(arr[i], arr[j]);
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // int pIdx = hoarePartition(arr, low, high);
        int pIdx = lomutoPartition(arr, low, high);

        quickSort(arr, low, pIdx - 1);
        // quickSort(arr, low, pIdx); // hoare
        quickSort(arr, pIdx + 1, high);
    }
}

void print(vector<int>& arr) {
    for (int x: arr) {
        cout << x << ", ";
    }
    cout << endl;
}

int main() {
    int k = 100;

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> distrib(1, k);

    vector<int> arr;
    // arr.reserve(k);

    // for (int i=k; i >= 1; --i) {
    //     arr.push_back(distrib(gen));
    //     // arr.push_back(i);
    // }

    arr = {13, 19, 9, 67, 94, 70, 11, 12, 72, 77, 21, 67, 78, 39, 37, 62, 28, 25, 21, 24, 90, 77, 72, 18, 51, 41, 14, 76, 21, 57, 56, 22, 72, 3, 34, 9, 90, 84, 22, 55, 26, 56, 85, 38, 27, 87, 65, 92, 17, 40, 42, 19, 29, 100, 95, 39, 9, 77, 92, 4, 100, 47, 15, 92, 88, 13, 14, 90, 61, 31, 7, 20, 19, 65, 96, 1, 88, 81, 75, 97, 19, 50, 80, 17, 16, 33, 15, 61, 41, 90, 11, 61, 65, 74, 94, 6, 52, 4, 35, 44};
    int n = arr.size();
    
    print(arr);

    quickSort(arr, 0, n-1);

    cout << "Sorted\n";

    print(arr);

    cout << cnt << endl;

    return 0;
}