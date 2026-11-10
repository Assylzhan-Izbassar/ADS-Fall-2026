#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() { 
    int nEdges;
    cin >> nEdges;

    vector<pair<int, int>> edges;
    int v, u;
    for (int i=0; i < nEdges; ++i) {
        cin >> v >> u;
        edges.push_back({v, u});
        edges.push_back({u, v});
    }

    for (pair<int, int> edge: edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0; 
}