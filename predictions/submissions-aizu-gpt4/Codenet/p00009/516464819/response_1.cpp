#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int main() {
    vector<int> inputs;
    int x;
    while (cin >> x) {
        inputs.push_back(x);
    }

    int maxInput = *max_element(inputs.begin(), inputs.end());
    vector<bool> primes = sieve(maxInput);

    for (int input : inputs) {
        cout << primes[input] << endl;
    }

    return 0;
}