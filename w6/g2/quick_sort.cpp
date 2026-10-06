#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

int cnt = 0;

int lomutoPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j=low; j <= high - 1; ++j) { // n
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
    if (low < high) { // log(n) -> n
        int pIdx = hoarePartition(arr, low, high);

        quickSort(arr, low, pIdx);
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
    arr.reserve(k);
    
    // for (int i=0; i <= k; ++i) {
    //     arr.push_back(distrib(gen));
    //     // arr.push_back(i+1); 
    // }

    arr = {41, 54, 50, 85, 62, 24, 46, 8, 62, 34, 93, 94, 42, 64, 15, 87, 66, 32, 6, 45, 24, 63, 63, 44, 40, 96, 27, 90, 59, 65, 76, 10, 93, 55, 4, 48, 65, 48, 10, 4, 87, 80, 57, 24, 41, 49, 52, 32, 40, 41, 79, 30, 48, 63, 98, 57, 41, 70, 47, 59, 12, 27, 57, 15, 100, 80, 99, 91, 36, 84, 100, 37, 100, 42, 4, 75, 76, 92, 98, 34, 18, 32, 23, 40, 66, 65, 92, 36, 14, 84, 75, 38, 94, 22, 3, 18, 1, 64, 33, 75, 22};
    int n = arr.size();
    
    // print(arr);
    
    quickSort(arr, 0, n-1);

    // cout << "sorted:\n";
    // print(arr);

    cout << cnt << endl;

    return 0;
}