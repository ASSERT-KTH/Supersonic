#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primes) {
  vector<bool> v(n + 1, true);
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
  vector<int> primes;
  vector<int> inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);
  sieve(*max_element(inputs.begin(), inputs.end()), primes);
  for (auto x : inputs) {
    // Use lower_bound to find the number of primes less than or equal to x
    int count = lower_bound(primes.begin(), primes.end(), x + 1) - primes.begin();
    cout << count << endl;
  }
  return 0;
}