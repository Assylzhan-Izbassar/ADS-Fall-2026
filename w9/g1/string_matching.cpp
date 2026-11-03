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

vector<ll> matching(string& text, string& patt) {
    int n = text.size(), m = patt.size();
    vector<ll> lpsPatt = lpsProcess(patt);

    int i = 0, j = 0;
    vector<ll> result;

    while (i < n) {
        if (text[i] == patt[j]) {
            i++;
            j++;

            if (j == m) {
                result.push_back(i - j);
                j = lpsPatt[j - 1];  // optimization step
            }
        } else {
            if (j > 0) {
                j = lpsPatt[j - 1];
            } else {
                i++;
            }
        }
    }
    return result;
}

int main() {
    string text = "ababacdabcaba";
    string patt = "aba";

    // vector<ll> lpsArray = lpsProcess(patt);
    vector<ll> matchedResult = matching(text, patt);

    // print(lpsArray);
    print(matchedResult);

    return 0;
}