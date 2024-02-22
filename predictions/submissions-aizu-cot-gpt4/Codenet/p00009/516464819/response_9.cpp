#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primes, unordered_set<int> &primeSet, vector<int> &counts) {
  vector<bool> isPrime(n + 1, true);
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!isPrime[i])
      continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      isPrime[j] = false;
  }
  primes.push_back(2);
  primeSet.insert(2);
  counts.push_back(1);
  for (int i = 3; i <= n; i += 2) {
    if (isPrime[i]) {
      primes.push_back(i);
      primeSet.insert(i);
    }
    counts.push_back(counts.back() + isPrime[i]);
  }
}

int main() {
  vector<int> primes;
  unordered_set<int> primeSet;
  vector<int> inputs, counts(1, 0);
  for (int x; cin >> x;)
    inputs.push_back(x);
  sieve(*max_element(inputs.begin(), inputs.end()), primes, primeSet, counts);
  for (auto x : inputs)
    cout << (primeSet.count(x) ? counts[x] : counts[x] - 1) << endl;
  return 0;
}