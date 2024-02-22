#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<int>& primes) {
  vector<bool> v(n + 1, true);
  for (int i = 3, end = sqrt(n); i <= end; i += 2) {
    if (!v[i])
      continue;
    int skip = i * 2;
    for (int j = i * i; j <= n; j += skip)
      v[j] = false;
  }
  primes.push_back(2);
  for (int i = 3; i <= n; i += 2) {
    if (v[i])
      primes.push_back(i);
  }
}

int countPrimes(const vector<int>& primes, int x) {
  int low = 0;
  int high = primes.size() - 1;
  int count = 0;
  
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (primes[mid] <= x) {
      count = mid + 1;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  
  return count;
}

int main() {
  vector<int> primes;
  vector<int> inputs;
  
  for (int x; cin >> x;) {
    inputs.push_back(x);
  }
  
  sieve(*max_element(inputs.begin(), inputs.end()), primes);
  
  for (auto x : inputs) {
    int count = countPrimes(primes, x);
    cout << count << endl;
  }
  
  return 0;
}