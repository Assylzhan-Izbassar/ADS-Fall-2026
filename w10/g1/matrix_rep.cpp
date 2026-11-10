#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

void print_ff(vector<vector<int>>& arr) {
    for (vector<int> x: arr) {
        for (int e: x) {
            cout << e << " ";
        }
        cout << endl;
    }
}

int main() { 
    int v;
    cin >> v;
    vector<vector<int>> graph(v, vector<int>(v, 0));

    for (int i=0; i < v; ++i) {
        for (int j=0; j < v; ++j) {
            cin >> graph[i][j];
        }
    }
    
    print_ff(graph);

    return 0; 
}