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

int charToInt(char c) { return c - 'a' + 1; }

vector<int> rabinKarp(string& text, string& patt) {
    int n = text.size();
    int m = patt.size();

    int p = 29;
    ll mod = 1e9 + 17;

    vector<ll> pPow(n + 1);
    pPow[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pPow[i] = (pPow[i - 1] * p) % mod;
    }

    vector<ll> hashText(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        hashText[i + 1] = (hashText[i] + charToInt(text[i]) * pPow[i]) % mod;
    }

    ll hashPatt = 0;
    for (int i = 0; i < m; ++i) {
        hashPatt = (hashPatt + charToInt(patt[i]) * pPow[i]) % mod;
    }

    vector<int> occ;

    for (int i = 0; i + m - 1 < n; ++i) {
        ll currHash = (hashText[i + m] - hashText[i] + mod) % mod;
        if (currHash == (hashPatt * pPow[i]) % mod) {
            occ.push_back(i);
        }
    }
    return occ;
}

int main() {
    string text = "ababa";  // all lowercases
    string patt = "ab";

    vector<int> occ = rabinKarp(text, patt);

    print(occ);

    return 0;
}