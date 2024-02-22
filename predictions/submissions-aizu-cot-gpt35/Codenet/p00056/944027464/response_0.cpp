#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(void) {
  const int MAX_N = 51000;
  bitset<MAX_N + 1> isPrime;
  isPrime.set(); // set all bits to 1

  for (int i = 2; i * i <= MAX_N; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX_N; j += i) {
        isPrime[j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i <= MAX_N; i++) {
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