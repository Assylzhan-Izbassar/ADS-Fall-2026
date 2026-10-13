#include <iostream>
#include <vector>
#include <map>

using namespace std;

int divide(vector<int> &nums, map<pair<int, int>, bool> &visited, map<int, int> &cnt, int left, int right, int target, int result)
{
    if (left <= right && !visited.count({left, right}))
    {
        visited[{left, right}] = true;
        result += 2 * cnt[target] > (right - left + 1);
        // cout << "f " << left << " " << right << endl;
        cnt[nums[right]]--;
        result = divide(nums, visited, cnt, left, right - 1, target, result);
        // cout << "s " << left << " " << right << endl;
        cnt[nums[right]]++;
        cnt[nums[left]]--;
        result = divide(nums, visited, cnt, left + 1, right, target, result);
        cnt[nums[left]]++;
        // cout << "t " << left << " " << right << endl;
        // cout << endl;
    }
    return result;
}

int countMajoritySubarrays(vector<int> &nums, int target)
{
    map<pair<int, int>, bool> visited;
    map<int, int> cnt;
    for (int i = 0; i < nums.size(); ++i)
    {
        cnt[nums[i]]++;
    }
    return divide(nums, visited, cnt, 0, nums.size() - 1, target, 0);
}

int main()
{
    vector<int> nums = {1, 2, 2, 3};
    int target = 2;

    cout << countMajoritySubarrays(nums, target) << endl;

    return 0;
}