#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> sieve(int n) {
  vector<bool> isPrime(n+1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 4; i <= n; i += 2)
    isPrime[i] = false;
  for (int i = 3; i * i <= n; i += 2)
    if (isPrime[i])
      for (int j = i * i; j <= n; j += i * 2)
        isPrime[j] = false;
  return isPrime;
}

int main() {
  vector<int> inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);
  auto primes = sieve(*max_element(inputs.begin(), inputs.end()));
  for (auto x : inputs) {
    int count = 0;
    for (int i = 2; i <= x; ++i)
      if (primes[i])
        ++count;
    cout << count << '\n';
  }
  return 0;
}