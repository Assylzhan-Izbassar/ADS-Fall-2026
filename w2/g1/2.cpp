#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> freq;
    queue<char> q;

    for (int i=0; i < s.size(); ++i) {
        freq[s[i]]++;
        q.push(s[i]);

        while (freq[q.front()] > 1) {
            q.pop();
        }
    }

    if (!q.empty()) {
        cout << q.front() << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}