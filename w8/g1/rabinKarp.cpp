#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int charToInt(char c) { return c - 'a' + 1; }

void print(vector<ll> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> rabinKarp(string text, string patt) {
    int p = 29;
    ll mod = 1e9 + 7;

    int n = text.size();
    int m = patt.size();

    vector<ll> pPow(max(n, m) + 1, 0);
    pPow[0] = 1;
    for (int i = 1; i < pPow.size(); ++i) {
        pPow[i] = (pPow[i - 1] * p) % mod;
    }
    print(pPow);

    vector<ll> hashText(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        hashText[i + 1] = (hashText[i] + charToInt(text[i]) * pPow[i]) % mod;
    }
    print(hashText);

    ll hashPatt = 0;
    for (int i = 0; i < m; ++i) {
        hashPatt = (hashPatt + charToInt(patt[i]) * pPow[i]) % mod;
    }

    cout << hashPatt << endl;

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
    string text, patt;  // lower letters
    text = "abbaba";
    patt = "ab";

    vector<int> occ = rabinKarp(text, patt);

    for (int i : occ) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}