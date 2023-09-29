#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<bool> sieve(int n) {
  vector<bool> isPrime(n + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (int i = 4; i <= n; i += 2)
    isPrime[i] = false;

  int end = sqrt(n);
  for (int i = 3; i <= end; i += 2) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i * 2)
        isPrime[j] = false;
    }
  }
  return isPrime;
}

int main() {
  vector<int> inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);

  int max_input = *max_element(inputs.begin(), inputs.end());
  vector<bool> isPrime = sieve(max_input);

  for (auto x : inputs) {
    int count = 0;
    for (int i = 2; i <= x; ++i)
      if (isPrime[i])
        ++count;
    cout << count << endl;
  }
  return 0;
}