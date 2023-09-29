#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void sieve(int n, vector<bool> &v, vector<int> &primes) {
  v.resize(n + 1, true);
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
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
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n;

  vector<bool> v;
  vector<int> primes;
  sieve(n, v, primes);

  while (n--) {
    cin >> x;
    auto it = lower_bound(primes.begin(), primes.end(), x);
    if (it == primes.end() || *it != x)
      cout << it - primes.begin() << '\n';
    else
      cout << it - primes.begin() + 1 << '\n';
  }

  return 0;
}