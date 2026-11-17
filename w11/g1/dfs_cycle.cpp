#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

// cycle detection for undirected graph
void dfs_cycle_detect(int v, int& cycleNum, vector<bool>& visited, vector<int>& parent, vector<vector<int>>& adj) {
    cout << v << " ";
    for (int i=0; i < adj[v].size(); ++i) {
        int u = adj[v][i];
        if (!visited[u]) {
            visited[u] = true;
            parent[u] = v;
            dfs_cycle_detect(u, cycleNum, visited, parent, adj);
        } else {
            if (parent[v] != u) {
                cycleNum++;
                // cout << "getting: " << v << " " << u << endl;
                // cout << "here: " << parent[v] << " " << u << endl; 
                // return true;
            }
        }
    }
    // return cycleNum;
    // return false;
}

/**
cyclic graph
5 6
0 1 
0 2
1 2 
1 3 
2 4 
3 4

cyclic graph
5 5
0 1 
0 2
1 2  
2 4 
3 4

acyclic graph
5 4
0 2
1 2 
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
    vector<int> parent(nV, -1);

    int start = 0;
    visited[start] = true;

    int result = 0;
    
    dfs_cycle_detect(start, result, visited, parent, adj);

    cout << endl;
    for (int x: parent) {
        cout << x << " "; 
    }

    cout << endl;
    cout << result / 2 << endl;

    return 0; 
}