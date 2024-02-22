#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int>& primesCount) {
  vector<bool> isPrime(n + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!isPrime[i])
      continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      isPrime[j] = false;
  }
  primesCount[2] = 1;
  for (int i = 3; i <= n; i += 2) {
    primesCount[i] = primesCount[i-1] + (isPrime[i] ? 1 : 0);
    if (i+1 <= n) {
      primesCount[i+1] = primesCount[i];
    }
  }
}

int main() {
  vector<int> inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);
  int maxInput = *max_element(inputs.begin(), inputs.end());
  vector<int> primesCount(maxInput + 1);
  sieve(maxInput, primesCount);
  for (auto x : inputs) {
    cout << primesCount[x] << endl;
  }
  return 0;
}