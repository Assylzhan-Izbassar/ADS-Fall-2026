#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> &arr)
{
    for (int x : arr)
    {
        cout << x << " ";
    }
}

int main()
{
    vector<int> a1 = {5, 1, 12, 4, 9}, a2 = {3, 15, 6};

    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    int n = a1.size(), m = a2.size();
    int i = 0, j = 0;

    vector<int> result;

    while (i < n && j < m)
    {
        if (a1[i] > a2[j])
        {
            result.push_back(a2[j]);
            j++;
        }
        else
        {
            result.push_back(a1[i]);
            i++;
        }
    }

    while (i < n)
    {
        result.push_back(a1[i]);
        i++;
    }

    while (j < m)
    {
        result.push_back(a2[j]);
        j++;
    }

    print(result);
    cout << "\n";

    return 0;
}