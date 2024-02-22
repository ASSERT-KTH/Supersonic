#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primes) {
  vector<bool> is_prime(n + 1, true);
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
  vector<int> primes;
  vector<int> inputs;
  int max_input = 0;
  for (int x; cin >> x;) {
    inputs.push_back(x);
    max_input = max(max_input, x);
  }
  sieve(max_input, primes);

  for (auto x : inputs) {
    auto count = upper_bound(primes.begin(), primes.end(), x) - primes.begin();
    cout << count << endl;
  }
  return 0;
}