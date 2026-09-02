#include <iostream>
#include <vector>
#include <map>

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

vector<int> findIntersection(vector<int>& f1, vector<int>& f2) {
    map<int, int> cnt;
    vector<int> result;
    
    for (int x: f1) {
        cnt[x]++;
    }

    for (int x: f2) {
        if (cnt.find(x) != cnt.end() && cnt[x] > 0) {
            cnt[x]--;
            result.push_back(x);
        }
    }
    return result;
}

int gcdEuclid(int a, int b) {
    if (b == 0) return a;
    return gcdEuclid(b, a % b);
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> factors1 = primeFactors(n1);
    vector<int> factors2 = primeFactors(n2);

    vector<int> commonFactors = findIntersection(factors1, factors2); 

    long long gcd = 1;
    for (int x: commonFactors) {
        cout << x << " ";
        gcd *= x;
    }
    cout << endl;
    cout << gcd << endl;

    cout << gcdEuclid(n1, n2) << endl;

    return 0;
}