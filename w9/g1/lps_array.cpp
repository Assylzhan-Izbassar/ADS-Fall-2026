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

vector<ll> lpsProcess(string& patt) {
    int n = patt.size();
    vector<ll> lps(n, 0);

    int len = 0, i = 1;

    while (i < n) {
        if (patt[len] == patt[i]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len > 0) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }
    }
    return lps;
}

int main() {
    string patt = "aba";

    vector<ll> lpsArray = lpsProcess(patt);

    print(lpsArray);

    return 0;
}