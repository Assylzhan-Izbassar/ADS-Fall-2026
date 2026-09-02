#include <iostream>
#include <vector>

using namespace std;

vector<int> ePrimes(int n) {
    vector<bool> primes(n+1, true);
    primes[0] = primes[1] = false;
    
    for (int i=2; i <= n; i++) {
        if (primes[i]) {
            if (i * 1ll * i <= n) {
                for (int j=i*i; j <= n; j=j+i) {
                    primes[j] = false;
                }
            }
        } 
    }

    vector<int> result;
    for (int i=2; i <= n; ++i) {
        if (primes[i]) result.push_back(i);
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes = ePrimes(n);
    
    for (int x: primes) {
        cout << x << " ";
    }
    cout << endl;
    cout << primes.size() << endl;

    return 0;
}