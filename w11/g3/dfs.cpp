#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

void dfs(int v, vector<bool>& visited, vector<vector<int>>& adj) {
    if (visited[v]) return;

    visited[v] = true;
    cout << v << " "; 

    for (int& u: adj[v]) {
        dfs(u, visited, adj);
    }
}

/*
Undirected graph
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
    int s = 0;
    vector<bool> visited(nV);

    dfs(s, visited, adj);

    cout << endl;

    return 0; 
}