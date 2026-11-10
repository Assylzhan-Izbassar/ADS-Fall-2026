#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int virusOccupy(int xv, int yv, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, INT32_MAX));

    // initial conditions
    visited[xv][yv] = true;
    q.push({xv, yv});
    dist[xv][yv] = 0;
    
    int result = 0;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> coor = q.front();
        q.pop();

        int vx = coor.first;
        int vy = coor.second;

        for (int i=0; i < 4; ++i) {
            int ux = vx + dx[i];
            int uy = vy + dy[i];

            if ((ux >= 0 && ux < n) && (uy >= 0 && uy < m) && !visited[ux][uy]) {
                visited[ux][uy] = true;
                q.push({ux, uy});
                dist[ux][uy] = dist[vx][vy] + 1;
                result = max(result, dist[ux][uy]);
            }
        }
    }

    for (int i=0; i < n; ++i) {
        for (int j=0; j < m; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return result;
}

int main() { 
    int n, m;
    cin >> n >> m;
    int xv, yv;
    cin >> xv >> yv;

    cout << virusOccupy(xv, yv, n, m) << endl;

    return 0; 
}