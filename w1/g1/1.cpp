#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;
using namespace chrono;

bool isPrime(int n) {
    if (n == 2) return true;

    for (int i=2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

vector<int> primes(int n) {
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
        cout << n << " is prime.\n";
    } else {
        cout << n << " is not prime.\n";
    }

    vector<int> ps = primes(n);
    // for (int x: ps) {
    //     cout << x << " ";
    // }
    // cout << endl;

    cout << ps.size() << endl;

    return 0;
}