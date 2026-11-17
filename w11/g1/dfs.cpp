#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int vertexPass = 0;
int edgePass = 0;

void dfs(int v, vector<bool>& visited, vector<vector<int>>& adj) {
    if (visited[v]) return; // return from rec.
    
    vertexPass++;
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < adj[v].size(); ++i) {
        edgePass++;
        int u = adj[v][i];
        dfs(u, visited, adj);
    }
}

/**
5 6
0 1 
0 2
1 2 
1 3 
2 4 
3 4
*/

int main() { 
    int nV, nE;
    cin >> nV >> nE;

    vector<vector<int>> adj(nV);

    int v, u;
    for (int i=0; i < nE; ++i) {
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<bool> visited(nV);

    dfs(0, visited, adj);

    cout << endl;

    cout << vertexPass << " " << edgePass << endl;

    return 0; 
}