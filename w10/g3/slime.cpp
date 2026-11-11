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

bool isInBound(int c, int b) {
    return (c >= 0 && c < b);
}

int compute(int xs, int ys, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    visited[xs][ys] = true;
    q.push({xs, ys});
    dist[xs][ys] = 0;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    int result = 0;

    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();

        for (int i=0; i < 4; ++i) {
            int ux = v.first + dx[i];
            int uy = v.second + dy[i];

            if (isInBound(ux, n) && isInBound(uy, m) && !visited[ux][uy]) {
                visited[ux][uy] = true;
                q.push({ux, uy});
                dist[ux][uy] = dist[v.first][v.second] + 1;

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
    int xs, ys;
    cin >> xs >> ys;

    vector<vector<int>> world(n, vector<int>(m));

    cout << compute(xs, ys, n, m) << endl;

    return 0; 
}