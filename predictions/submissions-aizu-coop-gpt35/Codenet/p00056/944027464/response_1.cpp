#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<char> isPrime(51000 + 1, false);
  isPrime[2] = true;
  memset(&isPrime[3], true, 51000 - 2);

  for (size_t i = 3; i < 51000; i += 2) {
    if (isPrime[i]) {
      for (size_t j = i + i; j < 51000; j += i) {
        isPrime[j] = false;
      }
    }
  }

  vector<int> primes;
  primes.reserve(5000);
  primes.push_back(2);
  for (size_t i = 3; i < 51000; i += 2) {
    if (isPrime[i])
      primes.push_back(i);
  }

  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for_each(primes.begin(), primes.end(), [&](int p) {
      if (p <= n / 2) {
        bool isPrimeFlag = isPrime[n - p];
        if (isPrimeFlag)
          kotae++;
      }
    });
    cout << kotae << '\n';
  }

  return 0;
}