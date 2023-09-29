#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void) {
  int limit = 51000 + 1;
  vector<bool> isPrime(limit, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 4; i < limit; i += 2) {
    isPrime[i] = false;
  }
  int sqrtLimit = sqrt(limit);
  for (int i = 3; i <= sqrtLimit; i += 2) {
    if (isPrime[i])
      for (int j = i * i; j < limit; j += i * 2) {
        isPrime[j] = false;
      }
  }
  vector<int> primes;
  for (int i = 2; i < limit; i++) {
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