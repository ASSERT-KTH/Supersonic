#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void sieve(int n, vector<bool>& isPrime) {
  isPrime.resize(n + 1, true);
  isPrime[0] = isPrime[1] = false;
  
  for (int i = 2, end = sqrt(n); i <= end; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

int main() {
  vector<bool> isPrime;
  int maxInput = 0;
  int x;
  
  while (cin >> x) {
    maxInput = max(maxInput, x);
  }
  
  sieve(maxInput, isPrime);
  
  vector<int> countPrimes(maxInput + 1, 0);
  
  for (int i = 2; i <= maxInput; ++i) {
    countPrimes[i] = countPrimes[i - 1] + isPrime[i];
  }
  
  cin.clear();
  cin.seekg(0, ios::beg);
  
  while (cin >> x) {
    cout << countPrimes[x] << endl;
  }
  
  return 0;
}