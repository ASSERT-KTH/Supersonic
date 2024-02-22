#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primeCounts) {
  vector<bool> isPrime(n + 1, true);
  primeCounts.resize(n + 1, 0);

  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= n; ++i) {
    if (isPrime[i]) {
      for (int j = i * 2; j <= n; j += i)
        isPrime[j] = false;
    }
    primeCounts[i] = primeCounts[i-1] + isPrime[i];
  }
}

int main() {
  vector<int> inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);

  int maxInput = *max_element(inputs.begin(), inputs.end());
  vector<int> primeCounts;
  sieve(maxInput, primeCounts);

  for (auto x : inputs)
    cout << primeCounts[x] << endl;

  return 0;
}