#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <utility>

using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> cnt;
    queue<pair<char, int>> q;

    for (int i=0; i < s.size(); ++i) {
        cnt[s[i]]++;
        q.push({s[i], i});

        while (cnt[q.front().first] > 1) {
            q.pop();
        }
    }

    if (q.empty()) {
        cout << -1 << "\n";
    } else {
        cout << q.front().second << "\n";
    }

    return 0;
}