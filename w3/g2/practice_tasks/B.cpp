#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearchLeftMost(vector<int>& a, int target) {
    int l = 0;
    int r = a.size();

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (a[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}

int binarySearchRightMost(vector<int>& a, int target) {
    int l = 0;
    int r = a.size();

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (a[mid] <= target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l - 1;
}

int main() {
    vector<int> a = {1, 2, 3, 3, 3, 6, 7, 10};
    int target = 7;

    int ans1 = binarySearchLeftMost(a, target);
    int ans2 = binarySearchRightMost(a, target);

    cout << ans1 << "\n";
    cout << ans2 << "\n";

    vector<int>::iterator it = lower_bound(a.begin(), a.end(), target);
    cout << it - a.begin() << endl;

    vector<int>::iterator it2 = upper_bound(a.begin(), a.end(), target);
    cout << it2 - a.begin() - 1 << endl;

    return 0;
}