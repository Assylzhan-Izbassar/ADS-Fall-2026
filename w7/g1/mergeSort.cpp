#include <iostream>
#include <vector>

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
    int n = mid - left + 1;
    int m = right - mid;

    cout << n << " " << m << endl;

    vector<int> L(n), R(m);

    for (int i = 0; i < n; ++i)
        L[i] = arr[i + left];
    for (int j = 0; j < m; ++j)
        R[j] = arr[j + mid + 1];

    print(L);
    cout << " - ";

    print(R);
    cout << endl;

    int i = 0, j = 0;
    int k = left;

    while (i < n && j < m)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
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
    if (left >= right)
        return;

    int mid = left + (right - left) / 2; // (left + right) / 2

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    vector<int> arr = {5, 10, 7, 20, 6};
    // vector<int> arr = {70, 30, 50, 10};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);

    print(arr);

    cout << endl;

    return 0;
}