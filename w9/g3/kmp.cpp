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

vector<int> kmp(string& text, string& patt) {  // O (n + 2m - 1) ~ O (n + m);
    int n = text.size(), m = patt.size();

    vector<int> result, lpsArray = countLPS(patt);  // O(m);
    int i = 0, j = 0;

    while (i < n) {  // n - operations
        if (text[i] == patt[j]) {
            i++;
            j++;

            if (j == m) {
                result.push_back(i - j);
                j = lpsArray[j - 1];
            }
        } else {
            if (j > 0) {
                j = lpsArray[j - 1];  // m - 1;
            } else {
                i++;
            }
        }
    }  // O(n + m - 1); => O(n * m / 2);

    return result;
}

int main() {
    string text = "abababbabdabababab";  // text >= patt;
    string patt = "abab";

    vector<int> result = kmp(text, patt);

    print(result);

    return 0;
}