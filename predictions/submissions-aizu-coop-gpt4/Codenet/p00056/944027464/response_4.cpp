#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int MAX = 51000;
  vector<bool> isPrime(MAX + 1, true); // Initialize all to true
  vector<int> primes;

  isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers
  primes.push_back(2); // Add 2 to the list of prime numbers

  // Sieve of Eratosthenes algorithm
  for (int i = 2; i * i <= MAX; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        isPrime[j] = false;
      }
    }
  }
  
  // Add prime numbers to the list
  for (int i = 3; i <= MAX; i += 2) {
    if (isPrime[i])
      primes.push_back(i);
  }

  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; i < primes.size(); i++) {
      if (primes[i] <= n / 2) {
        if (isPrime[n - primes[i]]) // Use [] instead of at
          kotae++;
      }
    }
    cout << kotae << endl;
  }
  return 0;
}