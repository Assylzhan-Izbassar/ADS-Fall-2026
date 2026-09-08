#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <utility>

using namespace std;

int main() {
    string s;
    cin >> s;

    queue<pair<char, int>> q;
    map<char, int> freq;

    for (int i=0; i < s.size(); ++i) {
        freq[s[i]]++;
        q.push({s[i], i});

        while (freq[q.front().first] > 1) {
            q.pop();
        }
    }

    if (!q.empty()) 
        cout << q.front().second << endl;
    else 
        cout << -1 << endl;

    return 0;
}