#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearchExc(vector<int>& a, int target) {
    int l = 0;
    int r = a.size();

    while (l < r) {
        int mid = l + (r - l) / 2; // to handle the overflow
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] > target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return -1;
}

int binarySearchInc(vector<int>& a, int target) {
    int l = 0;
    int r = a.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == target) {
            return mid;
        } else if (a[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i < n; ++i) cin >> a[i];

    int x;
    cin >> x;

    sort(a.begin(), a.end());
    int pos = binarySearchInc(a, x);
    
    if (pos != -1) {
        cout << "FOUND\n";
    } else {
        cout << "NOT FOUND\n";
    }

    return 0;
}