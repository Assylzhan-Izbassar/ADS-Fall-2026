#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() { 
    // input
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i=0; i < n; ++i) {
        for (int j=0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    cout << endl;
    for (int i=0; i < n; ++i) {
        for (int j=0; j < n; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    cout << graph[2][3] << endl;

    return 0; 
}