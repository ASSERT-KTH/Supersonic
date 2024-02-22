#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

int main(void) {
  bitset<51001> isPrime;
  isPrime.set();
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= 51000; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= 51000; j += i) {
        isPrime[j] = false;
      }
    }
  }

  int primesCount = count(isPrime.begin(), isPrime.end(), true);
  int primes[primesCount];
  int index = 0;
  for (int i = 0; i <= 51000; i++) {
    if (isPrime[i]) {
      primes[index++] = i;
    }
  }

  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; i < primesCount; i++) {
      if (primes[i] <= n / 2) {
        if (binary_search(primes, primes + primesCount, n - primes[i])) {
          kotae++;
        }
      }
    }
    cout << kotae << endl;
  }
  return 0;
}