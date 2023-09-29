#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
vector<int> sieve(int n) {
  vector<int> primes;
  vector<bool> v(n + 1, true);
  v[0] = v[1] = false;
  for (int i = 4; i <= n; i += 2)
    v[i] = false;
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!v[i])
      continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      v[j] = false;
  }
  for (int i = 2; i <= n; ++i)
    if (v[i])
      primes.push_back(i);
  return primes;
}
int main() {
  vector<int> inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);
  auto primes = sieve(*max_element(inputs.begin(), inputs.end()));
  for (auto x : inputs) {
    auto count = lower_bound(primes.begin(), primes.end(), x);
    cout << (count - primes.begin()) + 1 << endl;
  }
  return 0;
}