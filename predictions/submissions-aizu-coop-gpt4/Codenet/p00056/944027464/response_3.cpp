#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  std::ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> isPrime(51000 + 1, 1);
  isPrime[0] = isPrime[1] = 0;

  for (int i = 2; i * i <= 51000; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= 51000; j += i)
        isPrime[j] = 0;
    }
  }

  vector<int> primes;
  primes.reserve(51000);
  for (int i = 2; i <= 51000; ++i) {
    if (isPrime[i])
      primes.push_back(i);
  }

  int n;
  while (cin >> n && n != 0) {
    int kotae = upper_bound(primes.begin(), primes.end(), n / 2) - primes.begin();
    for (int i = 0; i < kotae; i++) {
      if (!isPrime[n - primes[i]])
        kotae--;
    }
    cout << kotae << endl;
  }
  return 0;
}