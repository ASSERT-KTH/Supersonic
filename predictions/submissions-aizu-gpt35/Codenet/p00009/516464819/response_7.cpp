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
    int count = 0;
    for (auto p : primes)
      if (p == x) {
        count++;
        break;
      } else if (p > x)
        break;
      else
        count++;
    cout << count << endl;
  }
  return 0;
}
