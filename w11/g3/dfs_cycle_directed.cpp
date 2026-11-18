#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

bool dfs_cycle_detect_optimized(int v, vector<bool>& visited, vector<bool>& path, vector<vector<int>>& adj) {
    if (path[v]) return true;
    
    if (visited[v]) return false;
    
    cout << v << " ";

    visited[v] = true;
    path[v] = true;

    for (int& u: adj[v]) {
        if (dfs_cycle_detect_optimized(u, visited, path, adj)) {
            return true;
        }
    }
    path[v] = false;

    return false;
}

bool dfs_cycle_detect(int v, vector<bool>& visited, stack<int>& ancestors, vector<vector<int>>& adj) {
    cout << v << " ";

    for (int& u: adj[v]) {
        if (!visited[u]) {
            visited[u] = true;
            ancestors.push(u);
            if (dfs_cycle_detect(u, visited, ancestors, adj)) {
                return true;
            }
        } else {
            stack<int> copy(ancestors);
            while (!copy.empty()) {
                int top = copy.top();
                if (top == u) {
                    return true;
                }
                copy.pop();
            }
        }
        ancestors.pop();
    }

    return false;
}

/*
Directed graph with cycle
5 7
0 1 
0 3
1 3 
2 1
3 2 
3 4
4 2

Directed graph without cycle
5 5
0 1 
0 3
1 3 
3 2 
4 2
*/

int main() { 
    int nV, nE;
    cin >> nV >> nE;

    vector<vector<int>> adj(nV);

    int v, u;
    for (int i=0; i < nE; ++i) {
        cin >> v >> u;
        adj[v].push_back(u);
    }
    int s = 0;
    vector<bool> visited(nV, false);
    
    // stack<int> ancestors;
    // visited[s] = true;
    // ancestors.push(s);
    // bool result = dfs_cycle_detect(s, visited, ancestors, adj);

    vector<bool> path(nV, false);
    bool result = dfs_cycle_detect_optimized(s, visited, path, adj);
    
    cout << endl;

    if (result) {
        cout << "The cycle is detected.\n"; 
    } else {
        cout << "The cycle is NOT detected.\n";
    }

    return 0; 
}