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
  int maxVal = *max_element(inputs.begin(), inputs.end());
  sieve(maxVal, primes);
  vector<int> primeCounts(maxVal + 1, 0);
  for (int i = 0, j = 0; i <= maxVal; i++) {
    if (j < primes.size() && primes[j] == i)
      j++;
    primeCounts[i] = j;
  }
  for (auto x : inputs)
    cout << primeCounts[x] << endl;
  return 0;
}