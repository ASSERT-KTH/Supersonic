#include <iostream>
#include <vector>
using namespace std;
int main() {
  const int limit = 51000;
  vector<bool> isPrime(limit + 1, false);
  isPrime[2] = true;
  for (int i = 3; i <= limit; i += 2) {
    isPrime[i] = true;
  }
  for (int i = 3; i * i <= limit; i += 2) {
    if (isPrime[i]) {
      for (int j = i * i; j <= limit; j += i) {
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
    for (int i = 0; i < primes.size() && primes[i] <= n / 2; i++) {
      if (isPrime[n - primes[i]])
        kotae++;
    }
    cout << kotae << endl;
  }
  return 0;
}