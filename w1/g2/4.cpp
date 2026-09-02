#include <iostream>
#include <vector>

using namespace std;

vector<int> primeFactors(int n) {
    vector<int> factors;
    int tempN = n;
    for (int i=2; i <= tempN / 2; ++i) {
        while (n % i == 0) {
            n /= i;
            factors.push_back(i);
        }
    }
    return factors;
}

int main() {
    int n;
    cin >> n;

    vector<int> factors = primeFactors(n);

    for (int x: factors) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}