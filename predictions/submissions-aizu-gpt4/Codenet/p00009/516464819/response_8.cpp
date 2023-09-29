#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
void sieve(int n, vector<int> &primes) {
  vector<bool> v(n + 1, true);
  v[0] = v[1] = false;
  for (int i = 4; i <= n; i += 2)
    v[i] = false;
  for (int i = 3, end = sqrt(n); i <= end; i += 2)
    if (v[i])
      for (int j = i * i; j <= n; j += i * 2)
        v[j] = false;
  for (int i = 2; i <= n; ++i)
    if (v[i])
      primes.push_back(i);
}
int main() {
  vector<int> primes, inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);
  sieve(*max_element(inputs.begin(), inputs.end()), primes);
  vector<int>::iterator it;
  for (auto x : inputs) {
    it = lower_bound(primes.begin(), primes.end(), x);
    cout << (it - primes.begin() + (*it == x)) << endl;
  }
  return 0;
}