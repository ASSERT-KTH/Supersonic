#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <vector>
using namespace std;
void sieve(int n, list<int> &primes) {
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
  list<int> primes;
  vector<int> inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);
  for (auto x : inputs) {
    int count = 0;
    for (auto p : primes)
      if (p == x) {
        count++;
        break;
      } else if (p > x)
        break;
      cout << count << endl;
    }
  return 0;
}
