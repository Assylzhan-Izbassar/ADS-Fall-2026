#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

vector<int> eratosPrimes(int n) {
    vector<bool> isPrimes(n + 1, true);
    isPrimes[0] = isPrimes[1] = false;

    for (int i=2; i <= n; ++i) {
        if (isPrimes[i]) {
            if (i * 1ll * i <= n) {
                for (int j=i*i; j <= n; j += i) {
                    isPrimes[j] = false;
                }
            }
        }
    }

    vector<int> realPrimes;
    for (int i=0; i <= n; ++i) {
        if (isPrimes[i]) {
            realPrimes.push_back(i);
        }
    }
    return realPrimes;
}

int main() {
    int n;
    cin >> n;

    // time_point start = steady_clock::now();

    vector<int> primes = eratosPrimes(n);

    // for (int x: primes) {
    //     cout << x << " ";
    // }
    // cout << endl;
    cout << primes.size() << endl;

    return 0;
}