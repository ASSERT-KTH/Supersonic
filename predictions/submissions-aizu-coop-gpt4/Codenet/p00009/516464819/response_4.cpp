#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primes) {
  vector<bool> v(n + 1, true);
  int end = sqrt(n);
  for (int i = 3; i <= end; i += 2) {
    if (!v[i])
      continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      v[j] = false;
  }
  primes.push_back(2);
  for (int i = 3; i <= n; i += 2)
    if (v[i])
      primes.push_back(i);
}

int main() {
  vector<int> primes;
  vector<int> inputs;
  int max_val = -1;
  for (int x; cin >> x;) {
    inputs.push_back(x);
    max_val = max(max_val, x);
  }
  sieve(max_val, primes);
  for (auto x : inputs) {
    auto it = upper_bound(primes.begin(), primes.end(), x);
    cout << distance(primes.begin(), it) << endl;
  }
  return 0;
}