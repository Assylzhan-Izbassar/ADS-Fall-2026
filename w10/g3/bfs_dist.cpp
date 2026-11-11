#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> bfs(int src, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    vector<int> dist(n, 0);

    vector<int> result;

    // 1. initilize the base case;
    visited[src] = true;
    q.push(src);
    dist[src] = 0;
    result.push_back(src);

    // 2. processing the vertices;
    while (!q.empty()) {
        int v = q.front();
        q.pop(); // processed

        // 3. processing the neighbors of v.
        for (int u: adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                dist[u] = dist[v] + 1;
                result.push_back(u);
            }
        }
    }

    print(dist);

    return result;
}

/**
5 6 - n, m - undirected graph
0 1 
0 2
1 2 
1 3 
2 4 
3 4
*/

int main() { 
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    int v, u;
    for (int i=0; i < m; ++i) {
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<int> result = bfs(4, adj);

    print(result);

    return 0; 
}