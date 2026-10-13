#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> &result)
{
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> a1 = {5, 1, 12, 4, 9}, a2 = {3, 15, 6};
    // sort(a1.begin(), a1.end());
    // sort(a2.begin(), a2.end());

    print(a1);
    print(a2);

    int n = a1.size();
    int m = a2.size();

    vector<int> result;

    int i = 0, j = 0;

    // for (; i < min(n, m); ++i)
    // {
    //     if (a1[i] > a2[j])
    //     {
    //         result.push_back(a2[j]);
    //         j++;
    //         i--;
    //     }
    //     else
    //     {
    //         result.push_back(a1[i]);
    //     }
    // }

    while (i < n && j < m)
    {
        if (a1[i] >= a2[j])
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

    cout << i << " " << j << endl;

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

    return 0;
}