#include <iostream>
#include <vector>

using namespace std;

bool f(int x, int n) {
    return x * x <= n;
}

void solution(int n) {
    int l = 1;
    int r = n / 2;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (f(mid, n)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << l - 1 << endl;
}

int main() {
    int n;
    cin >> n;

    solution(n);

    return 0;
}