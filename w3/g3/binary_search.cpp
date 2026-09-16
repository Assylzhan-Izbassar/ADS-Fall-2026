#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>& a, int target) {
    int leftIdx = 0; // included
    int rightIdx = a.size(); // excluded

    while (leftIdx < rightIdx) {
        int mid = (leftIdx + rightIdx) / 2;

        if (a[mid] == target) {
            return mid;
        } else if (a[mid] > target) {
            rightIdx = mid;
        } else {
            leftIdx = mid + 1;
        }
    }

    return -1;
}

int binarySearchInclude(vector<int>& a, int target) {
    int leftIdx = 0;
    int rightIdx = a.size() - 1;

    while (leftIdx <= rightIdx) {
        int mid = (leftIdx + rightIdx) / 2;
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] > target) {
            rightIdx = mid - 1;
        } else {
            leftIdx = mid + 1;
        }
    }
    return -1;
}

int binarySearchLeftmost(vector<int>& a, int target) {
    int l = 0;
    int r = a.size();

    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int binarySearchRightmost(vector<int>& a, int target) {
    int l = 0;
    int r = a.size();

    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return r - 1;
}

int binarySearchIfNotExist(vector<int>& a, int target) {
    int l = 0;
    int r = a.size()-1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] >= target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r + 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i < n; ++i) cin >> a[i];

    int target;
    cin >> target;

    sort(a.begin(), a.end()); // mandatory
    for (int x: a) {
        cout << x << " ";
    }
    cout << endl;

    int ans = binarySearch(a, target);
    int ans2 = binarySearchInclude(a, target);
    int ans3 = binarySearchLeftmost(a, target);
    int ans4 = binarySearchRightmost(a, target);

    int notExist;
    cin >> notExist;

    int ans5 = binarySearchIfNotExist(a, notExist);

    cout << ans << "\n";
    cout << ans2 << "\n";
    cout << ans3 << "\n";
    cout << ans4 << "\n";
    cout << ans5 << "\n";

    return 0;
}