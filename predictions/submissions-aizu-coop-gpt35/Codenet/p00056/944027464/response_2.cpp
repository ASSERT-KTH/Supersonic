#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main(void) {
  const int LIMIT = 51000;
  bitset<LIMIT + 1> isPrime;
  isPrime.set();
  
  // Apply the sieve algorithm
  for (int i = 3; i * i <= LIMIT; i += 2) {
    if (isPrime[i]) {
      for (int j = i * i; j <= LIMIT; j += i) {
        isPrime[j] = false;
      }
    }
  }
  
  vector<int> primes;
  primes.reserve(LIMIT / 2); // Reserve memory for primes
  
  primes.push_back(2);
  for (int i = 3; i <= LIMIT; i += 2) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }
  
  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    int size = primes.size();
    for (int prime : primes) {
      if (prime > n / 2) {
        break;
      }
      if (isPrime[n - prime]) {
        kotae++;
      }
    }
    cout << kotae << endl;
  }
  
  return 0;
}