#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

void dfs(int v, vector<bool>& visited, vector<int>& order, vector<vector<int>>& adj) {
    visited[v] = true;

    for (int& u: adj[v]) {
        if (!visited[u])
            dfs(u, visited, order, adj);
    }

    order.push_back(v);
}

void topSort(int nV, vector<vector<int>>& adj) {
    vector<bool> visited(nV);
    vector<int> order;

    for (int v=0; v < nV; ++v) {
        if (!visited[v]) {
            dfs(v, visited, order, adj);
        }
    }

    reverse(order.begin(), order.end());

    print(order);
}

/*
Directed acyclic graph
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

    topSort(nV, adj);

    cout << endl;

    return 0; 
}