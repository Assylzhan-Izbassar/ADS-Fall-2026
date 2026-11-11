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
    int n, m; // # edges
    cin >> n >> m;

    vector<vector<int>> adj(n);

    int v, u;
    for (int i=0; i < m; ++i) {
        cin >> v >> u;
        adj[v].push_back(u); 
        adj[u].push_back(v); 
    }
    
    for (int i=0; i < n; ++i) {
        cout << i << ": ["; 
        for (int j=0; j < adj[i].size(); ++j) {
            cout << adj[i][j] << ",";
        } 
        cout << "]\n";
    }
    

    return 0; 
}