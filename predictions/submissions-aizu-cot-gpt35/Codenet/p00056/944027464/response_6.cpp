#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
  const int limit = 51000;
  const int sqrtLimit = sqrt(limit);

  bitset<limit + 1> isPrime;
  isPrime[2] = true;
  for (int i = 3; i <= limit; i += 2) {
    isPrime[i] = true;
  }
  for (int i = 3; i <= sqrtLimit; i += 2) {
    if (isPrime[i]) {
      for (int j = i * i; j <= limit; j += i * 2) {
        isPrime[j] = false;
      }
    }
  }

  vector<int> primes;
  primes.push_back(2);
  for (int i = 3; i <= limit; i += 2) {
    if (isPrime[i])
      primes.push_back(i);
  }

  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    int primesSize = primes.size();
    for (int i = 0; i < primesSize; i++) {
      if (primes[i] <= n / 2) {
        if (isPrime[n - primes[i]])
          kotae++;
      }
    }
    cout << kotae << endl;
  }

  return 0;
}