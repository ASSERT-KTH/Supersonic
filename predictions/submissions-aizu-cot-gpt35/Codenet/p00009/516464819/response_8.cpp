#include <cmath>
#include <iostream>
#include <list>
#include <set>
using namespace std;

void sieve(int n, set<int>& primes) {
  vector<bool> v(n + 1, true);
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!v[i])
      continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      v[j] = false;
  }
  primes.insert(2);
  for (int i = 3; i <= n; i += 2)
    if (v[i])
      primes.insert(i);
}

int main() {
  list<int> primes;
  primes.reserve(100000);
  set<int> inputs;
  int x;
  while (cin >> x)
    inputs.insert(x);
  sieve(*inputs.rbegin(), primes);
  for (auto x : inputs) {
    int count = distance(primes.begin(), primes.lower_bound(x));
    cout << count << endl;
  }
  return 0;
}