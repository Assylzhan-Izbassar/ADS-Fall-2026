#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i < n; ++i) cin >> a[i];

    int target;
    cin >> target;

    // linear search
    bool isFound = false;
    for (int i=0; i < n; ++i) {
        if (a[i] == target) {
            cout << "FOUND\n";
            isFound = true;
            break;
        }
    }
    if (!isFound) {
        cout << "NOT FOUND\n";
    }

    return 0;
}