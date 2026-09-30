#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    vector<int> a = {10, 7, 8, 1, 5, 9};

    priority_queue<int, vector<int>, greater<int>> minPq(a.begin(), a.end());

    while (!minPq.empty()) {
        int t = minPq.top();
        minPq.pop();
        cout << t << " "; 
    }
    cout << endl;

    return 0;
}