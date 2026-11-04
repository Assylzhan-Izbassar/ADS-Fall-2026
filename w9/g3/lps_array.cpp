#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> countLPS(string& patt) {
    int m = patt.size();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m) {
        if (patt[len] == patt[i]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len > 0) {
                len = lps[len - 1];  // core optimization step
            } else {
                // lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
    string patt = "ababaa";

    vector<int> lpsArray = countLPS(patt);

    print(lpsArray);

    return 0;
}