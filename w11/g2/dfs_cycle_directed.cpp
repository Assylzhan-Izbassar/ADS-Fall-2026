#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

pair<bool, int> dfs_cycle_detect(int v, pair<bool, int> result, vector<bool>& visited, vector<vector<int>>& adj) {
    cout << v << " ";
    
    for (int& u: adj[v]) {
        if (visited[u] == true) {
            return {false, u};
        }
        visited[u] = true;
        result = dfs_cycle_detect(u, result, visited, adj);
        
        if (result.second == v) {
            return {true, result.second};
        } else if (result.second != -1) {
            return result;
        }
    }

    return result;
}

/*
directed graph with cycle
5 6
0 1
0 4
1 2
2 3
3 1
4 3

directed graph without cycle
5 5
0 1
0 4
1 2
2 3
4 3
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

    int start = 0;
    vector<bool> visited(nV, false); 
    
    visited[start] = true;
    pair<bool, int> result = {false, -1};
    result = dfs_cycle_detect(start, result, visited, adj);
    cout << endl;
    
    if (result.first) {
        cout << "A cycle is detected\n";
    } else {
        cout << "A cycle is NOT detected\n";
    }

    return 0; 
}
