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

ll hashF(string& s, int i, ll prevHash, vector<ll>& pPow, ll mod) {
    return (prevHash + charToInt(s[i]) * pPow[i]) % mod;
}

vector<int> rabinKarp(string& text, string& patt) {
    int n = text.size();
    int m = patt.size();

    int p = 29;
    int mod = 1e9 + 17;

    vector<ll> pPow(max(n, m) + 1);
    pPow[0] = 1;

    for (int i = 1; i <= max(n, m); ++i) {
        pPow[i] = (pPow[i - 1] * p) % mod;
    }

    vector<ll> hashText(n + 1, 0);
    for (int i = 0; i <= n; ++i) {
        hashText[i + 1] = hashF(text, i, hashText[i], pPow, mod);
    }

    ll hashPatt = 0;
    for (int i = 0; i < m; ++i) {
        // hashPatt = hashPatt + patt[i] * pPow[i];
        hashPatt = hashF(patt, i, hashPatt, pPow, mod);
    }

    vector<int> occ;
    for (int i = 0; i + m - 1 < n; ++i) {
        ll currHash = (hashText[i + m] - hashText[i] + mod) % mod;
        if (currHash ==
            (hashPatt * pPow[i]) % mod) {  // TODO: check their with example
            occ.push_back(i);
        }
    }
    return occ;
}

int main() {
    string text = "abba";
    string patt = "ab";

    vector<int> result = rabinKarp(text, patt);

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}