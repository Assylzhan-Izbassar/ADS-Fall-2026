#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& a, int target) {
    int leftIdx = 0;
    int rightIdx = a.size(); // convension r is excluded.

    while (leftIdx < rightIdx) {
        int midIdx = (leftIdx + rightIdx) / 2;

        if (a[midIdx] == target) {
            return midIdx;
        } else if (a[midIdx] > target) {
            rightIdx = midIdx;
        } else {
            leftIdx = midIdx + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i < n; ++i) cin >> a[i];

    int target;
    cin >> target;

    sort(a.begin(), a.end()); // O(n log(n))

    int idx = binarySearch(a, target);
    
    if (idx == -1) {
        cout << "NOT FOUND\n";
    } else {
        cout << "FOUND\n";
        cout << idx << "\n";
    }

    return 0;
}