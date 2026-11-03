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

vector<int> kmp(string& text, string& patt) {
    vector<int> result, lpsPatt = lpsProcess(patt);  // m
    int n = text.size(), m = patt.size();

    int i = 0, j = 0;
    while (i < n) {  // n
        if (text[i] == patt[j]) {
            i++;
            j++;

            if (j == m) {  // we found the patt in text;
                result.push_back(i - j);
                j = lpsPatt[j - 1];  // step back
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
    string text = "ababaababacdababaababaacd";
    string patt = "ababaa";

    vector<int> result = kmp(text, patt);

    print(result);

    return 0;
}