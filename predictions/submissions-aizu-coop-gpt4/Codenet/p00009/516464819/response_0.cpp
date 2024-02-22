#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primes) {
  vector<bool> v(n + 1, true);
  for (int i = 2, end = sqrt(n); i <= end; i++) {
    if (!v[i])
      continue;
    for (int j = i * i; j <= n; j += i)
      v[j] = false;
  }
  for (int i = 2; i <= n; i++)
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
    cout << lower_bound(primes.begin(), primes.end(), x + 1) - primes.begin() << endl;
  }
  return 0;
}