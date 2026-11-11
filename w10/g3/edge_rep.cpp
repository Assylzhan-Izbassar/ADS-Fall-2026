#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() { 
    // input
    int n, m; // # vertices, edges
    cin >> n >> m;

    vector<pair<int, int>> edges;

    int v, u;
    for (int i=0; i < m; ++i) {
        cin >> v >> u;
        edges.push_back({v, u});
        edges.push_back({u, v});
    }
    
    cout << endl;
    for (int i=0; i < edges.size(); ++i) {
        int v = edges[i].first;
        int u = edges[i].second;

        cout << v << " " << u << endl;
    }
    

    return 0; 
}