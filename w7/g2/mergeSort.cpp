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
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
    {
        L[i] = arr[i + left];
    }

    for (int j = 0; j < n2; ++j)
    {
        R[j] = arr[j + mid + 1];
    }

    cout << left << " " << mid << " " << right << endl;

    print(L);
    cout << " <-> ";
    print(R);

    cout << endl;

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2)
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

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
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
        int mid = left + (right - left) / 2; // (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr = {5, 10, 6, 12, 21, 9};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    print(arr);

    cout << endl;

    return 0;
}