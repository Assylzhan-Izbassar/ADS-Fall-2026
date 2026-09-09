#include <iostream>
#include <vector>

using namespace std;

vector<int> primeFactors(int x) {
    int n = x;
    vector<int> result;
    for (int i=2; i <= n; ++i) {
        while (x % i == 0) {
            result.push_back(i);
            x /= i;
        }
    }
    return result;
}

void print(vector<int> a) {
    for (int x: a) {
        cout << x << " ";
    }
    cout << "\n";
}

vector<int> findIntersec(vector<int>& a, vector<int>& b) {
    int i, j;
    i = j = 0;

    vector<int> result;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            result.push_back(a[i]);
            i++;
            j++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            i++;
        }
    }
    if (result.empty()) {
        result.push_back(1);
    }
    return result;
}

int main() {
    int a,b;
    cin >> a >> b;

    vector<int> aPrimes = primeFactors(a); // O(n-2) ~ O(n)
    vector<int> bPrimes = primeFactors(b); // O(n)

    print(aPrimes);
    print(bPrimes);

    vector<int> intersect = findIntersec(aPrimes, bPrimes); // O(min(len(a), len(b)))

    print(intersect);

    long long gcd = 1;
    for (int x: intersect) { // O(n)
        gcd *= x;
    }
    cout << "GCD of " << a << " and " << b << " is " << gcd << "\n";
    
    return 0;
}