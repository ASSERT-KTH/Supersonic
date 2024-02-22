#include <iostream>
#include <list>
using namespace std;

void sieve(int n, list<int>& primes) {
  vector<bool> v(n + 1, true);
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!v[i])
      continue;
    for (int j = i * i, skip = i * 2; j <= n; j += skip)
      v[j] = false;
  }
  primes.emplace_back(2);
  for (int i = 3; i <= n; i += 2)
    if (v[i])
      primes.emplace_back(i);
}

int main() {
  list<int> primes;
  vector<int> inputs;
  int numInputs;
  cin >> numInputs;
  inputs.reserve(numInputs);
  for (int i = 0; i < numInputs; i++) {
    int x;
    cin >> x;
    inputs.emplace_back(x);
  }
  sieve(*max_element(inputs.begin(), inputs.end()), primes);
  for (const auto& x : inputs) {
    int count = 0;
    for (const auto& p : primes) {
      if (p == x) {
        count++;
        break;
      } else if (p > x) {
        break;
      } else {
        count++;
      }
    }
    cout << count << '\n';
  }
  return 0;
}