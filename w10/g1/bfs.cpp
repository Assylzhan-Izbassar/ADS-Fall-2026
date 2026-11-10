#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

void print_ff(vector<vector<int>>& arr) {
    for (vector<int> x: arr) {
        for (int e: x) {
            cout << e << " ";
        }
        cout << endl;
    }
}

void bfs(int start, vector<vector<int>>& graph) { // graph - adjacency list
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    vector<int> dist(graph.size(), INT32_MAX);

    vector<int> result;

    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    result.push_back(start);


    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u: graph[v]) {
            if (!visited[u]) {
                visited[u] = true;
                result.push_back(u);

                dist[u] = min(dist[u], dist[v] + 1);

                q.push(u);
            }
        }
    }

    print(result);
    print(dist);
    
    for (int i=0; i < graph.size(); ++i) {
        cout << i << " - " << visited[i] << endl;
    }
}

int main() { 
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n);

    int v, u;
    for (int i=0; i < e; ++i) {
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    
    // print_ff(graph);

    bfs(2, graph);

    return 0; 
}