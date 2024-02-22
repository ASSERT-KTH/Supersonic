#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primes, vector<int> &primeCounts) {
  vector<char> isPrime(n + 1, true);
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!isPrime[i]) continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      isPrime[j] = false;
  }
  primes.push_back(2);
  primeCounts[2] = 1;
  for (int i = 3; i <= n; i += 2) {
    if (isPrime[i]) primes.push_back(i);
    primeCounts[i] = primeCounts[i-1] + isPrime[i];
    if(i+1 <= n) primeCounts[i+1] = primeCounts[i];
  }
}

int main() {
  vector<int> primes;
  vector<int> inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);
  int maxInput = *max_element(inputs.begin(), inputs.end());
  vector<int> primeCounts(maxInput + 1, 0);
  sieve(maxInput, primes, primeCounts);
  for (auto x : inputs)
    cout << primeCounts[x] << endl;
  return 0;
}