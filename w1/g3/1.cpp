#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i=2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    } // O(sqrt(n)) complexity.
    return true;
}

vector<int> getAllPrimes(int n) {
    vector<int> primes;
    for (int i=2; i <= n; ++i) { // O(n * sqrt(n))
        if (isPrime(i)) { // O(sqrt(n))
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << n << " is prime!\n";
    } else {
        cout << n << " is not prime!\n";
    }

    vector<int> primes = getAllPrimes(n);

    // for (int x: primes) {
    //     cout << x << " ";
    // }
    // cout << endl;

    cout << primes.size() << endl;

    return 0;
}