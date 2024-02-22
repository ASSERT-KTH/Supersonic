#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void sieve(int n, vector<int> &primes, unordered_map<int, bool> &primeCheck) {
  vector<bool> v(n + 1, true);
  int end = sqrt(n);
  for (int i = 3; i <= end; i += 2) {
    if (!v[i])
      continue;
    int skip = i * 2;
    for (int j = i * i; j <= n; j += skip)
      v[j] = false;
  }
  primes.push_back(2);
  primeCheck[2] = true;
  for (int i = 3; i <= n; i += 2) {
    if (v[i]) {
      primes.push_back(i);
      primeCheck[i] = true;
    }
  }
}

int main() {
  vector<int> primes;
  unordered_map<int, bool> primeCheck;
  vector<int> inputs;
  for (int x; cin >> x;)
    inputs.push_back(x);
  sieve(*max_element(inputs.begin(), inputs.end()), primes, primeCheck);
  for (auto x : inputs) {
    int count = 0;
    for (auto p : primes) {
      if (p > x)
        break;
      if (primeCheck[x]){
        count++;
        break;
      } else
        count++;
    }
    cout << count << endl;
  }
  return 0;
}