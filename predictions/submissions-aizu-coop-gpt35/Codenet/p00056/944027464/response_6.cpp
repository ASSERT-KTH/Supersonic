#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main(void) {
  const int N = 51000;
  bitset<N + 1> isPrime;
  isPrime.set();
  isPrime.reset(0);
  isPrime.reset(1);
  
  for (int i = 3; i * i <= N; i += 2) {
    if (isPrime.test(i)) {
      for (int j = i * i; j <= N; j += i * 2) {
        isPrime.reset(j);
      }
    }
  }

  vector<int> primes;
  primes.push_back(2);
  for (int i = 3; i <= N / 2; i += 2) {
    if (isPrime.test(i)) {
      primes.push_back(i);
    }
  }

  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; i < primes.size(); i++) {
      if (primes[i] <= n / 2) {
        if (isPrime.test(n - primes[i])) {
          kotae++;
        }
      }
    }
    cout << kotae << endl;
  }
  return 0;
}