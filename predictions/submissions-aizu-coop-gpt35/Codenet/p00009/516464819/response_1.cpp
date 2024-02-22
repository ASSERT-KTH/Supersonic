#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int>& primes) {
  vector<bool> v(n + 1, true);
  for (int i = 3, end = sqrt(n); i <= n; i += 2) {
    if (!v[i])
      continue;
    primes.push_back(i);
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      v[j] = false;
  }
}

int main() {
  vector<int> primes;
  vector<int> inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);
  sieve(*max_element(inputs.begin(), inputs.end()), primes);
  for (auto x : inputs) {
    int count = lower_bound(primes.begin(), primes.end(), x) - primes.begin();
    if (count < primes.size() && primes[count] == x)
      count++;
    cout << count << endl;
  }
  return 0;
}