#include <iostream>
#include <vector>

using namespace std;

int binarySearchWithPos(vector<int>& a, int target) {
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

int main() {
    vector<int> a = {1, 2, 3, 6, 7, 10};
    int target = 11;

    int ans = binarySearchWithPos(a, target);

    cout << ans << "\n";

    return 0;
}