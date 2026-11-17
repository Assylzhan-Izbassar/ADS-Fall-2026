#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int vertexPass = 0, edgePass = 0;

// v - starting vertex also
void dfs1(int v, vector<bool>& visited, vector<vector<int>>& adj) {
    if (visited[v] == true) return;

    visited[v] = true;
    cout << v << " ";

    for (int& u: adj[v]) {
        dfs1(u, visited, adj);
    }
}

void dfs2(int v, vector<bool>& visited, vector<vector<int>>& adj) {
    cout << v << " ";

    vertexPass++;
    
    for (int& u: adj[v]) {
        edgePass++;
        if (visited[u] == true) continue;
        visited[u] = true;
        dfs2(u, visited, adj);
    }
}

/*
6 7
0 1
0 2
1 2
1 3
2 4
2 5
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

    int start = 0;
    vector<bool> visited(nV, false); 
    
    visited[start] = true;
    dfs2(start, visited, adj);

    cout << endl;

    cout << vertexPass << " " << edgePass << endl; 

    return 0; 
}