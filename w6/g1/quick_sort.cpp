#include <iostream>
#include <vector>
#include <algorithm>

#include <random>

using namespace std;

int cnt = 0;

int lomutoPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1; // excluded

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

int partition(vector<int>& arr, int low, int high) {
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

        if (i >= j) {
            // cout << "j: " << j << "\n";
            return j;
        }

        swap(arr[i], arr[j]);
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pIdx = partition(arr, low, high);

        quickSort(arr, low, pIdx);
        quickSort(arr, pIdx + 1, high);
    }
}

int main() {

    random_device rd; 
    mt19937 gen(rd());

    int k = 20;

    uniform_int_distribution<int> distrib(1, k); 

    vector<int> arr;
    arr.reserve(k);
    
    // for (int i=0; i < k; ++i) {
    //     arr.push_back(distrib(gen));
    //     // arr.push_back(i+1);
    // }
    arr = {12, 6, 8, 14, 4, 1, 6, 15, 6, 13, 10, 13, 3, 1, 10, 7, 5, 16, 5, 4};

    for (int x: arr) {
        cout << x << ", ";
    }
    cout << endl;
    

    int n = arr.size();
    quickSort(arr, 0, n - 1);

    cout << "sorted:" << endl;
    for (int x: arr) {
        cout << x << " ";
    }
    cout << endl;

    cout << cnt << endl;

    return 0;
}