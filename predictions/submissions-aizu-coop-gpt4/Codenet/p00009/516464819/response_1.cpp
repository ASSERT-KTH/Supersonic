#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

void sieve(int n, vector<int> &primes) {
    vector<bool> is_prime(n+1, true);
    for (int i = 3, end = sqrt(n); i <= end; i += 2) {
        if (!is_prime[i])
            continue;
        for (int j = i * i, skip = i * 2; j <= n; j += skip)
            is_prime[j] = false;
    }
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
        if (is_prime[i])
            primes.push_back(i);
}

int main() {
    vector<int> primes, inputs;
    for (int x; cin >> x;)
        inputs.push_back(x);
    sieve(*max_element(inputs.begin(), inputs.end()), primes);
    for (auto x : inputs) {
        cout << (upper_bound(primes.begin(), primes.end(), x) - primes.begin()) << endl;
    }
    return 0;
}