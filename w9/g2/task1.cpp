#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> lpsProcess(vector<int>& patt) {
    int n = patt.size();
    vector<int> lps(n, 0);

    int len = 0, i = 1;

    while (i < n) {
        if (patt[len] == patt[i]) {
            len++;  // we found next len;
            lps[i] = len;
            i++;  // go next;
        } else {
            if (len > 0) {
                len = lps[len - 1];  // step back - optimizing part;
            } else {
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmp(vector<int>& nums, vector<int>& patt) {
    vector<int> result, lpsPatt = lpsProcess(patt);  // m
    int n = nums.size(), m = patt.size();

    int i = 0, j = 0;
    while (i < n) {  // n
        if (nums[i] == patt[j]) {
            i++;
            j++;

            if (j == m) {  // we found the patt in text;
                result.push_back(i - j);
                j = lpsPatt[j - 1];  // step back
            }
        } else {
            if (j > 0) {
                j = lpsPatt[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}

bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
    vector<int> pos;
    int lastPos = -1;
    int lastPosLen = -1;
    for (vector<int> group : groups) {
        vector<int> result = kmp(nums, group);
        if (!result.empty()) {
            print(result);
            int validPos = -1;
            if (lastPos == -1) {
                validPos = result[0];
                lastPosLen = group.size();
            } else {
                for (int x : result) {
                    if (lastPos + lastPosLen - 1 < x) {
                        lastPos = x;
                        lastPosLen = group.size();
                        validPos = lastPos;
                        break;
                    }
                }
            }
            cout << lastPos << " " << lastPosLen << endl;
            pos.push_back(validPos);
        }
    }

    if (pos.empty() || pos.size() != groups.size()) return false;

    for (int i = 0; i + 1 < pos.size(); ++i) {
        if (pos[i] > pos[i + 1]) return false;
        if (pos[i] + groups[i].size() - 1 >= pos[i + 1]) return false;
    }
    return true;
}

int main() {
    // vector<vector<int>> groups = {{1, -1, -1}, {3, -2, 0}};
    // vector<int> nums = {1, -1, 0, 1, -1, -1, 3, -2, 0};

    // vector<vector<int>> groups = {{1, 2, 3}, {3, 4}};
    // vector<int> nums = {7, 7, 1, 2, 3, 4, 7, 7};

    // vector<vector<int>> groups = {{10, -2}, {1, 2, 3, 4}};
    // vector<int> nums = {1, 2, 3, 4, 10, -2};

    // vector<vector<int>> groups = {{2, 1}};
    // vector<int> nums = {12, 1};

    vector<vector<int>> groups = {{-27}, {-40}};
    vector<int> nums = {
        10,  18,  41,  -13, 25,  48,  -40, 40,  -34, -13, 17,  43,  32, -28,
        28,  -19, -47, 45,  3,   42,  -2,  33,  28,  -9,  -11, -16, 3,  34,
        -30, -6,  32,  23,  24,  -14, -14, 1,   40,  -43, -34, 40,  23, 9,
        14,  14,  -31, 50,  -18, -23, -19, -21, 38,  24,  -41, -28, 47, -8,
        17,  -34, -45, -24, 7,   -5,  7,   -23, -42, -4,  31,  48,  40, 15,
        -27, -39, 50,  -40, 38,  -18, 26,  17,  49,  -18, 28,  9,   3,  42,
        5,   -43, 9,   -36, 15,  38,  -15, -33, -21, 4,   -11, 24,  -15};

    cout << canChoose(groups, nums) << "\n";

    return 0;
}