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

vector<int> bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    
    vector<bool> visited(n, false);
    queue<int> q;
    vector<int> dist(n, INT32_MAX);

    vector<int> result;

    // initial conditions
    visited[start] = true;
    q.push(start);
    dist[start] = 0;
    result.push_back(start);


    while (!q.empty()) {
        int v = q.front();
        q.pop();

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

    for (int i=0; i < adj.size(); ++i) {
        cout << i << ": [";
        for (int j=0; j < adj[i].size(); ++j) {
            cout << adj[i][j] << " ";
        }
        cout << "]\n";
    }  
    
    vector<int> result = bfs(0, adj);

    print(result);

    return 0; 
}