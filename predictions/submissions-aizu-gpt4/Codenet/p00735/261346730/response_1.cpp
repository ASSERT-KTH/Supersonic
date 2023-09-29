#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 300000 + 1;
vector<int> primes;

void sieve() {
    vector<bool> isPrime(MAX, true);
    for (int p = 2; p*p <= MAX; p++) {
        if (isPrime[p] == true && (p % 7 == 1 || p % 7 == 6)) {
            for (int i=p*2; i<=MAX; i += p)
                isPrime[i] = false;
        }
    }
    for (int p=2; p<=MAX; p++)
        if (isPrime[p] && (p % 7 == 1 || p % 7 == 6))
            primes.push_back(p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    while (true) {
        int n;
        cin >> n;
        if (n == 1)
            break;

        vector<int> ans;
        for (auto p : primes) {
            if (n % p == 0) {
                ans.push_back(p);
            }
        }

        cout << n << ':';
        for (auto p : ans) {
            cout << " " << p;
        }
        cout << "\n";
    }

    return 0;
}