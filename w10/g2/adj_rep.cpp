#include <iostream>
#include <vector>

using namespace std;

void ff_print(vector<vector<int>> graph) {
    for (int i=0; i < graph.size(); ++i) {
        for (int j=0; j < graph[i].size(); ++j) {
            cout <<  graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() { 
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i=0; i < n; ++i) {
        for (int j=0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> adj(n);

    for (int i=0; i < n; ++i) {
        for (int j=0; j < n; ++j) {
            if (graph[i][j] == 1) {
                adj[i].push_back(j);
            }
        }
    }

    ff_print(adj);
    

    return 0; 
}