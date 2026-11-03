#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void print(vector<ll>& arr) {
    for (ll x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

vector<ll> flps(string& patt) {
    int n = patt.size();
    vector<ll> lps(n, 0);

    int len = 0, i = 1;

    while (i < n) {
        if (patt[i] == patt[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }
    }

    return lps;
}

vector<ll> match(string& text, string& patt) {
    vector<ll> result, lps = flps(patt);

    int m = patt.size();
    int n = text.size();

    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == patt[j]) {
            i++;
            j++;

            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}

int main() {
    string t = "jakegotogolangos";
    string p = "go";

    vector<ll> res = match(t, p);

    print(res);

    return 0;
}