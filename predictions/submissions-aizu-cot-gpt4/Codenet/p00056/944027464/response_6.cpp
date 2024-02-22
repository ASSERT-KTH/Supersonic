#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void) {
  vector<bool> isPrime(51000 + 1, true);
  vector<int> primes;
  primes.reserve(51000); // Reserve memory in advance
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i*i <= 51000; i++) {
    if (isPrime[i]) {
      for (int j = i*i; j <= 51000; j += i) {
        isPrime[j] = false;
      }
    }
  }
  for (int i = 2; i <= 51000; i++) {
    if (isPrime[i])
      primes.push_back(i);
  }
  int n;
  int size = primes.size(); // Store size in a variable
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; i < size; i++) {
      if (primes[i] <= n / 2) {
        if (isPrime[n - primes[i]]) // Use operator [] instead of at()
          kotae++;
      }
    }
    cout << kotae << endl;
  }
  return 0;
}