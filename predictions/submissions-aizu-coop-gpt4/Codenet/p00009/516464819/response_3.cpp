#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primes, vector<int> &primeCount) {
  vector<bool> isPrime(n + 1, true);
  primeCount[2] = 1;
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!isPrime[i]) continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      isPrime[j] = false;
  }
  for (int i = 3; i <= n; i += 2)
    if (isPrime[i]) {
      primes.push_back(i);
      primeCount[i] = primeCount[i - 1] + 1;
    } else {
      primeCount[i] = primeCount[i - 1];
    }
}

int main() {
  vector<int> primes;
  vector<int> inputs;
  for (int x; cin >> x;) inputs.push_back(x);
  int maxInput = *max_element(inputs.begin(), inputs.end());
  vector<int> primeCount(maxInput + 1, 0);
  sieve(maxInput, primes, primeCount);
  for (auto x : inputs) {
    cout << primeCount[x] << endl;
  }
  return 0;
}