#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int>& primes) {
  vector<bool> isPrime(n + 1, true);

  // Only check up to the square root of n
  int end = sqrt(n);
  for (int i = 3; i <= end; i += 2) {
    if (!isPrime[i])
      continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      isPrime[j] = false;
  }

  primes.push_back(2);
  for (int i = 3; i <= n; i += 2) {
    if (isPrime[i])
      primes.push_back(i);
  }
}

int main() {
  vector<int> primes;
  vector<int> inputs;

  // Read inputs
  for (int x; cin >> x;) {
    inputs.push_back(x);
  }

  // Find the maximum input number
  int maxInput = *max_element(inputs.begin(), inputs.end());

  // Generate primes up to the maximum input number
  sieve(maxInput, primes);

  // Count primes for each input
  for (auto x : inputs) {
    int count = 0;
    for (auto p : primes) {
      if (p > x)
        break;
      count++;
    }
    cout << count << endl;
  }

  return 0;
}