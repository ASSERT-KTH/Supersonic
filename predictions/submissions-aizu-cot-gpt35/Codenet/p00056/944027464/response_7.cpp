#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

int main(void) {
  vector<bool> isPrime(51000, false);
  isPrime[2] = true;
  
  int sqrtLimit = sqrt(51000);
  
  for (int i = 3; i <= sqrtLimit; i += 2) {
    if (isPrime[i]) {
      for (int j = i * i; j < 51000; j += 2 * i) {
        isPrime[j] = false;
      }
    }
  }
  
  unordered_set<int> primes;
  primes.insert(2);
  
  for (int i = 3; i < 51000; i += 2) {
    if (isPrime[i])
      primes.insert(i);
  }
  
  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    int limit = n / 2;
    for (int prime : primes) {
      if (prime > limit)
        break;
      if (primes.count(n - prime))
        kotae++;
    }
    cout << kotae << endl;
  }
  
  return 0;
}