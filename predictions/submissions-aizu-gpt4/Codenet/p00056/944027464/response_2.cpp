#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_NUM = 51000;
int main(void) {
  vector<bool> isPrime(MAX_NUM + 1, true);
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= MAX_NUM; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX_NUM; j += i) {
        isPrime[j] = false;
      }
    }
  }
  
  vector<int> primes;
  for (int i = 2; i <= MAX_NUM; ++i) {
    if (isPrime[i])
      primes.push_back(i);
  }

  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; i < primes.size() && primes[i] <= n / 2; ++i) {
      if (isPrime[n - primes[i]])
        ++kotae;
    }
    cout << kotae << endl;
  }
  return 0;
}