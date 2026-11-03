#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> lpsProcess(string& patt) {
    int n = patt.size();
    vector<int> lps(n, 0);

    int len = 0, i = 1;

    while (i < n) {
        if (patt[len] == patt[i]) {
            len++;  // we found next len;
            lps[i] = len;
            i++;  // go next;
        } else {
            if (len > 0) {
                len = lps[len - 1];  // step back - optimizing part;
            } else {
                i++;
            }
        }
    }
    return lps;
}

int main() {
    string patt = "ababaa";

    vector<int> lps = lpsProcess(patt);

    print(lps);

    return 0;
}