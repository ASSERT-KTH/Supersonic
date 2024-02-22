#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primes) {
  vector<bool> v(n + 1, true);
  primes.push_back(2);
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!v[i])
      continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      v[j] = false;
  }
  for (int i = 3; i <= n; i += 2)
    if (v[i])
      primes.push_back(i);
}

int main() {
  vector<int> primes, inputs;
  int max_input = 0;
  for (int x; cin >> x;) {
    inputs.push_back(x);
    max_input = max(max_input, x);
  }
  sieve(max_input, primes);
  for (auto x : inputs) {
    int count = upper_bound(primes.begin(), primes.end(), x) - primes.begin();
    cout << count << endl;
  }
  return 0;
}