#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primes) {
  vector<bool> prime(n + 1, true);
  prime[0] = prime[1] = false;

  for (int p = 2; p*p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p*p; i <= n; i += p)
        prime[i] = false;
    }
  }
  
  for (int p = 2; p <= n; p++)
    if (prime[p])
      primes.push_back(p);
}

int main() {
  vector<int> primes;
  vector<int> inputs;
  int x;
  while (cin >> x)
    inputs.push_back(x);
  
  sieve(*max_element(inputs.begin(), inputs.end()), primes);
  
  for (auto &x : inputs) {
    cout << upper_bound(primes.begin(), primes.end(), x) - primes.begin() << endl;
  }
  return 0;
}