#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> getAllPrimes(int n) {
    vector<bool> potPrimes(n+1, true);
    potPrimes[0] = potPrimes[1] = false;

    for (int i=2; i <= n; ++i) {
        if (potPrimes[i]) {
            if (i * 1ll * i <= n) {
                for (int j=i*i; j <= n; j += i) {
                    potPrimes[j] = false;
                }
            }
        }
    }
    
    vector<int> primes;
    for (int i=2; i < potPrimes.size(); ++i) {
        if (potPrimes[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes = getAllPrimes(n);

    // for (int x: primes) {
    //     cout << x << " ";
    // }
    // cout << endl;

    cout << primes.size() << endl;

    return 0;
}