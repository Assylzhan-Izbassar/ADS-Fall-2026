#include <iostream>
#include <vector>
#include <utility>

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
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> edges;

    int v, u;
    for (int i=0; i < e; ++i) {
        cin >> v >> u;
        edges.push_back({v, u});
    }
    
    for (pair<int, int> edge: edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0; 
}