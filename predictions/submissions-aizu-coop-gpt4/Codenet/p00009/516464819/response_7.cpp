#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primes, vector<int> &prime_count) {
  vector<bool> is_prime(n + 1, true);
  primes.push_back(2);
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!is_prime[i])
      continue;
    primes.push_back(i);
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      is_prime[j] = false;
  }
  for (int i = *primes.rbegin() + 2; i <= n; i += 2)
    if (is_prime[i])
      primes.push_back(i);
  prime_count.resize(n + 1, 0);
  int count = 0;
  for (int i = 0; i <= n; ++i) {
    if (binary_search(primes.begin(), primes.end(), i))
      ++count;
    prime_count[i] = count;
  }
}

int main() {
  vector<int> primes, inputs, prime_count;
  int max_input = 0;
  for (int x; cin >> x;) {
    inputs.push_back(x);
    max_input = max(max_input, x);
  }
  sieve(max_input, primes, prime_count);
  for (auto x : inputs)
    cout << prime_count[x] << endl;
  return 0;
}