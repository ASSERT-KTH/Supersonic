#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  vector<int> isPrime(51000 + 1, 0);
  isPrime[2] = 1;
  for (int i = 3; i < 51000; i += 2) {
    isPrime[i] = 1;
  }

  // Start checking multiples from the square of each prime number
  for (int i = 3; i * i < 51000; i += 2) {
    if (isPrime[i]) {
      for (int j = i * i; j < 51000; j += i) {
        isPrime[j] = 0;
      }
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
    // Limit prime number iteration
    for (int i = 0; primes[i] <= n / 2; i++) {
      if (isPrime[n - primes[i]])
        kotae++;
    }
    cout << kotae << endl;
  }
  return 0;
}