#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primes, vector<int> &prime_count) {
  vector<bool> v(n + 1, true);
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!v[i])
      continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      v[j] = false;
  }
  primes.push_back(2);
  prime_count[2] = 1;
  for (int i = 3; i <= n; i += 2) {
    if (v[i]) {
      primes.push_back(i);
      prime_count[i] = prime_count[i-2] + 1;
    } else {
      prime_count[i] = prime_count[i-2];
    }
  }
}

int main() {
  vector<int> primes;
  vector<int> inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);
  int max_input = *max_element(inputs.begin(), inputs.end());
  vector<int> prime_count(max_input + 1, 0);
  sieve(max_input, primes, prime_count);
  for (auto x : inputs)
    cout << prime_count[x] << endl;
  return 0;
}