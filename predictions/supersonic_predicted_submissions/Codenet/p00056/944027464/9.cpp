#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  vector<bool> isPrime(51000 + 1, false);
  isPrime[2] = true;
  for (int i = 3; i < 51000; i += 2)
    isPrime[i] = true;
  for (int i = 3; i < 51000; i += 2) {
    for (int j = i + i; j < 51000; j += i) {
      isPrime[j] = false;
    }
  }
  vector<int> primes;
  primes.push_back(2);
  for (int i = 3; i < 51000; i += 2) {
    if (isPrime[i])
      primes.push_back(i);
  }
  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; i < primes.size(); i++) {
      if (primes[i] <= n / 2) {
        if (isPrime.at(n - primes[i]))
          kotae++;
      }
    }
    cout << kotae << endl;
  }
  return 0;
}
