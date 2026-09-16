/*
Find the integer part of the sqrt(n).
*/

#include <iostream>
#include <vector>

using namespace std;

bool f(int n, int ans) { // create some validator
    return ans * ans <= n;
};

void solution(int n) {
    int l = 1; // determine some domain
    int r = n;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (f(n, mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << l - 1 << "\n"; 
}

int main() {
    int n;
    cin >> n;

    solution(n);

    return 0;
}