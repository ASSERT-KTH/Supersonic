#include <iostream>
#include <vector>
using namespace std;

const int MAX = 51000;
vector<bool> isPrime(MAX + 1, true);
vector<int> primes;

void sieve() {
    isPrime[0] = isPrime[1] = false;

    for (int i = 4; i <= MAX; i += 2) {
        isPrime[i] = false;
    }

    for (int i = 3; i <= MAX; i += 2) {
        if (isPrime[i]) {
            for (int j = i + i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }

    primes.push_back(2);
    for (int i = 3; i <= MAX; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();

    int n;
    while (cin >> n && n != 0) {
        int kotae = 0;
        for (int i = 0; primes[i] <= n / 2; i++) {
            if (isPrime[n - primes[i]]) {
                kotae++;
            }
        }
        cout << kotae << '\n';
    }
    return 0;
}