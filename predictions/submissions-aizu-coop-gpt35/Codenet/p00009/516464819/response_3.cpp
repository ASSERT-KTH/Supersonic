#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int>& primes) {
  vector<char> v(n + 1, true);
  int end = sqrt(n);
  for (int i = 2; i <= n; i++) {
    if (!v[i])
      continue;
    for (int j = i * i; j <= n; j += i)
      v[j] = false;
  }
  for (int i = 2; i <= n; i++) {
    if (v[i])
      primes.push_back(i);
  }
}

int main() {
  vector<int> primes;
  vector<int> inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);
  sieve(*max_element(inputs.begin(), inputs.end()), primes);
  for (auto x : inputs) {
    int count = upper_bound(primes.begin(), primes.end(), x) - primes.begin();
    cout << count << endl;
  }
  return 0;
}