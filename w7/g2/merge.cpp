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
    cout << endl;
}

int main()
{
    vector<int> a1 = {5, 1, 12, 4, 9};
    vector<int> a2 = {3, 15, 6};

    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    int n1 = a1.size();
    int n2 = a2.size();

    vector<int> result;

    int i = 0, j = 0;

    while (i < n1 && j < n2)
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

    while (i < n1)
    {
        result.push_back(a1[i]);
        i++;
    }

    while (j < n2)
    {
        result.push_back(a2[j]);
        j++;
    }

    cout << i << " " << j << endl;
    print(result);
    return 0;
}