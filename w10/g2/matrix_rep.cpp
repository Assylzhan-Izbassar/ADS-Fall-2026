#include <iostream>
#include <vector>

using namespace std;

void ff_print(vector<vector<int>> graph) {
    int n = graph.size();
    for (int i=0; i < graph.size(); ++i) {
        for (int j=0; j < n; ++j) {
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

    ff_print(graph);

    return 0; 
}