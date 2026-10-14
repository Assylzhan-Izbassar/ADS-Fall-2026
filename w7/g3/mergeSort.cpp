#include <iostream>
#include <vector>
#include <random>

using namespace std;

void print(vector<int> &arr)
{
    for (int x : arr)
    {
        cout << x << " ";
    }
}

void merge(vector<int> &arr, int left, int mid, int right)
{
    // Block 1 - taking the copy of elements - L, R
    int n = mid - left + 1; // see the + 1;
    int m = right - mid;

    vector<int> L(n), R(m);
    for (int i = 0; i < n; ++i)
    {
        L[i] = arr[i + left];
    }
    for (int j = 0; j < m; ++j)
    {
        R[j] = arr[j + mid + 1]; // see the + 1;
    }

    // Block 2 - merging of L and R
    int i = 0, j = 0;
    int k = left;

    while (i < n && j < m)
    {
        if (L[i] >= R[j])
        {
            arr[k] = R[j];
            j++;
        }
        else
        {
            arr[k] = L[i];
            i++;
        }
        k++;
    }

    while (i < n)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < m)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    random_device rd;
    mt19937 gen(rd());

    int k = 100000;

    uniform_int_distribution<int> dist(1, k);

    // vector<int> arr = {70, 30, 50, 10};
    vector<int> arr;
    arr.reserve(k);

    for (int i = 0; i < k; ++i)
        arr.push_back(k + 1);

    // print(arr);

    int n = arr.size();
    mergeSort(arr, 0, n - 1);

    // cout << "\nsorted:\n";

    // print(arr);

    return 0;
}