#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int>& primes) {
  vector<bool> isPrime(n + 1, true);
  primes.push_back(2);
  for (int i = 3; i <= n; i += 2) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= n; j += i * 2) {
        isPrime[j] = false;
      }
    }
  }
}

int main() {
  vector<int> primes;
  int x;
  vector<int> inputs;

  while (cin >> x) {
    inputs.push_back(x);
  }

  sieve(*max_element(inputs.begin(), inputs.end()), primes);

  for (auto x : inputs) {
    int count = 0;
    for (auto p : primes) {
      if (p == x) {
        count++;
        break;
      } else if (p > x) {
        break;
      } else {
        count++;
      }
    }
    cout << count << endl;
  }

  return 0;
}