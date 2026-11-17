#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

bool dfs_cycle_detect(int v, vector<int>& parent, vector<bool>& visited, vector<vector<int>>& adj) {
    for (int& u: adj[v]) {
        if (!visited[u]) {
            visited[u] = true;
            parent[u] = v;
            if(dfs_cycle_detect(u, parent, visited, adj)) return true;
        } else {
            if (parent[v] != u) {
                return true;
            }
        }
    }
    return false;
}

/*
undirected graph with cycle
5 6
0 1
0 2
1 2
1 3
2 4
3 4

undirected graph without cycle
5 4
0 1
0 2
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

    int start = 0;
    vector<bool> visited(nV, false); 
    vector<int> parent(nV);

    visited[start] = true;
    parent[start] = -1;
    
    bool result = dfs_cycle_detect(start, parent, visited, adj);
    cout << endl;
    
    if (result) {
        cout << "A cycle is detected\n";
    } else {
        cout << "A cycle is NOT detected\n";
    }

    return 0; 
}
