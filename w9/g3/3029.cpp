#include <iostream>
#include <vector>

using namespace std;

int minimumTimeToInitialState(string word, int k) {
    string text = word + "#" + word;
    int ans = 1;
    int currPos = k;

    while (ans < word.size() / k + 1) {
        int i = currPos + 1,
            len = currPos;
        int checkPos = currPos + 2 * (word.size() - currPos) + 1;
        int arrLen = checkPos - currPos;

        vector<int> lpsArray(arrLen); 
        while (i < checkPos) {
            if (text[len] == text[i]) {
                len++;
                lpsArray[i - ans * k] = len - currPos;
                i++;
            } else {
                if (len - currPos > 0) {
                    len = lpsArray[len - currPos - 1] + currPos;
                } else {
                    i++;
                }
            }
        }

        if (lpsArray[lpsArray.size() - 1] == word.size() - currPos) {
            break;
        } else {
            currPos += k;
        }
        ans++;
    }

    return ans;
}

int main () {
    return 0;
}
