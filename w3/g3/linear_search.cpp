#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i=0; i < n; ++i) cin >> a[i];

    int y;
    cin >> y;

    int cnt = 0; // linear search
    for (int i=0; i < n; ++i) {
        if (a[i] == y) {
            cnt++;
        }
    }
    
    cout << cnt << "\n";

    return 0;
}