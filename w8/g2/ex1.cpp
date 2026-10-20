#include <iostream>
#include <vector>

using namespace std;

vector<int> findMissingElements(vector<int>& nums) {
    unordered_map<int, int> m;
    for (int i = 100; i >= 1; --i) {
        m[i] = 0;
    }
    int small = 100;
    int highest = 1;

    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]]++;
        small = min(small, nums[i]);
        highest = max(highest, nums[i]);
    }

    vector<int> result;
    unordered_map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
        int key = (*it).first;
        int value = (*it).second;
        cout << key << " " << value << endl;
        if (key >= small && key <= highest && value == 0) {
            result.push_back(key);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {12, 44};
    vector<int> result = findMissingElements(nums);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}