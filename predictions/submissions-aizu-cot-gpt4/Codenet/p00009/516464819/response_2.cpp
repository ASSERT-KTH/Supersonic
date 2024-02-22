#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void sieve(int n, vector<int> &primes, vector<bool> &isPrime) {
  vector<bool> v(n + 1, true);
  v[0] = v[1] = false;

  for (int i = 2; i*i <= n; i++) {
    if (v[i]) {
      for (int j = i * i; j <= n; j += i)
        v[j] = false;
    }
  }

  for (int i = 2; i <= n; i++) {
    if (v[i])
      primes.push_back(i);
  }

  isPrime = v;
}

int main() {
  vector<int> primes;
  vector<bool> isPrime;
  int maxInput = 0;
  vector<int> inputs;

  for (int x; cin >> x;) {
    inputs.push_back(x);
    maxInput = max(maxInput, x);
  }

  sieve(maxInput, primes, isPrime);
  
  for (auto x : inputs) {
    cout << (isPrime[x] ? primes[x] : 0) << endl;
  }

  return 0;
}