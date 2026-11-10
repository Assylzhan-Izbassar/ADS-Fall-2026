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

int virus_bfs(int x_s, int y_s, vector<vector<int>>& graph) { 
    int n = graph.size();
    int m = graph[n-1].size();
    
    vector<vector<int>> visited(n, vector<int>(m, false));
    queue<pair<int, int>> q;

    vector<vector<int>> dist(n, vector<int>(m, INT32_MAX));

    int result = 0;

    q.push({x_s, y_s});
    visited[x_s][y_s] = true;
    dist[x_s][y_s] = 0;

    vector<int> dx = {-1, 1, 0, 0}; 
    vector<int> dy = {0, 0, -1, 1};


    while (!q.empty()) {
        pair<int, int> coor = q.front();
        q.pop();
        int vx = coor.first;
        int vy = coor.second;

        for (int i = 0; i < 4; ++i) {
            int ux = vx + dx[i];
            int uy = vy + dy[i];

            if ((ux >= 0 && ux < n) && (uy >= 0 && uy < m) && !visited[ux][uy]) {
                visited[ux][uy] = true;
                dist[ux][uy] = min(dist[ux][uy], dist[vx][vy] + 1);
                result = max(result, dist[ux][uy]);
                q.push({ux, uy}); 
            }
        }
    }
    return result;
}

int main() { 
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    
    vector<vector<int>> matrix(n, vector<int>(m, INT32_MAX));

    cout << virus_bfs(x, y, matrix);

    return 0; 
}