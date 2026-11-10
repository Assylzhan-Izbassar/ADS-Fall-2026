#include <iostream>
#include <vector>

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

int main() { 
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n);

    int v, u;
    for (int i=0; i < e; ++i) {
        cin >> v >> u;
        graph[v].push_back(u);
    }
    
    print_ff(graph);

    return 0; 
}