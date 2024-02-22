#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    const int maxNum = 51000;
    vector<bool> isPrime(maxNum + 1, false);
    isPrime[2] = true;
    for (int i = 3; i <= maxNum; i += 2) {
        isPrime[i] = true;
    }
    for (int i = 3; i <= maxNum; i += 2) {
        if (isPrime[i]) {  // Only check for prime numbers
            for (int j = i + i; j <= maxNum; j += i) {
                isPrime[j] = false;
            }
        }
    }
    vector<int> primes;
    primes.reserve(maxNum/2);  // Preallocate memory
    primes.push_back(2);
    for (int i = 3; i <= maxNum; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    int n;
    while (cin >> n && n != 0) {
        int kotae = 0;
        for (int i = 0; i < primes.size() && primes[i] <= n / 2; i++) {
            if (isPrime[n - primes[i]]) {
                kotae++;
            }
        }
        cout << kotae << endl;
    }
    return 0;
}