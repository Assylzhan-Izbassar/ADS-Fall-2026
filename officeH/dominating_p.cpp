#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

void solve(int n) {
    vector<string> patts(n);
    // string p;

    for (int i=0; i < n; ++i) {
        cin >> patts[i];
    }

    string text;
    cin >> text;
}

int main() { 
    int n;

    while (cin >> n && n != 0) {
        solve(n); 
    }
    return 0; 
}