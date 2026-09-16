#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> a, int target) {
    int l = 0, r = a.size();

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (a[mid] == target) {
            while (true) {
                if (a[--mid] != target) {
                    return mid + 1;
                }
            }
        }
        else if (a[mid] > target) r = mid;
        else l = mid + 1;
    }
    return -1;
}

int binarySearchActual(vector<int> a, int target) {
    int l = 0, r = a.size();

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (a[mid] >= target)
            r = mid;
        else 
            l = mid + 1;
    }
    return l;
}

int main() {

    vector<int> a = {1, 3, 4, 4, 4, 5, 7, 7, 7, 9};
    int target = 7;

    int target2 = 2;

    bool ans_ = binary_search(a.begin(), a.end(), target2);
    cout << ans_ << "\n";

    vector<int>::iterator it = lower_bound(a.begin(), a.end(), target);
    cout << it - a.begin() << endl;

    vector<int>::iterator it2 = upper_bound(a.begin(), a.end(), target);
    cout << it2 - a.begin() - 1 << endl;

    int ans = binarySearch(a, target);

    cout << ans << "\n";

    return 0;
}