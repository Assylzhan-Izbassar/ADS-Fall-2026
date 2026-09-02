#include <iostream>
#include <vector>

using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;
    int tempN = n;
    for (int i=2; i <= tempN / 2; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    return factors;
}

int main() {
    int n;
    cin >> n;

    vector<int> factors = primeFactors(n);

    long long testN = 1.0;
    for (int x: factors) {
        cout << x << " "; 
        testN *= x;
    }
    cout << endl;
    cout << testN << endl;

    return 0;
}