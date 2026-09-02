#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i=2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> allPrimesUntil(int n) {
    vector<int> result;
    for (int i=2; i <= n; ++i) {
        if (isPrime(i)) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << n << " is prime." << endl;
    } else {
        cout << n << " is not prime." << endl;
    }

    vector<int> primes = allPrimesUntil(n);

    for (int x: primes) {
        cout << x << " "; 
    }
    cout << endl;
    cout << primes.size() << endl;

    return 0;
}