#include <iostream>
#include <vector>
using namespace std;

long long mergeSort(vector<int> &pref, vector<int> &temp,
                    int left, int right)
{
    if (left >= right)
    {
        return 0;
    }

    int mid = left + (right - left) / 2;

    long long result = 0;

    result += mergeSort(pref, temp, left, mid);
    result += mergeSort(pref, temp, mid + 1, right);

    int i = left;

    for (int j = mid + 1; j <= right; ++j)
    {
        while (i <= mid && pref[i] < pref[j])
        {
            ++i;
        }

        result += i - left;
    }

    i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (pref[i] <= pref[j])
        {
            temp[k++] = pref[i++];
        }
        else
        {
            temp[k++] = pref[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = pref[i++];
    }

    while (j <= right)
    {
        temp[k++] = pref[j++];
    }

    for (int p = left; p <= right; ++p)
    {
        pref[p] = temp[p];
    }

    return result;
}

long long countMajoritySubarrays(vector<int> &nums, int target)
{
    int n = nums.size();

    vector<int> pref(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        pref[i + 1] = pref[i] +
                      (nums[i] == target ? 1 : -1);
    }

    vector<int> temp(n + 1);

    return mergeSort(pref, temp, 0, n);
}

int main()
{
    vector<int> nums = {1, 3, 3, 2, 3};
    int target = 3;

    cout << countMajoritySubarrays(nums, target) << '\n';

    return 0;
}