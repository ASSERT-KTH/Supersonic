#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  const int N = 51000;
  bitset<N + 1> isPrime;
  isPrime.set();
  isPrime[0] = isPrime[1] = false;

  int sqrtN = sqrt(N);
  for (int i = 2; i <= sqrtN; ++i) {
    if (isPrime[i]) {
      for (int j = i * i; j <= N; j += i) {
        isPrime[j] = false;
      }
    }
  }

  vector<int> primes;
  primes.reserve(N / log(N));

  for (int i = 2; i <= N; ++i) {
    if (isPrime[i]) {
      primes.emplace_back(i);
    }
  }

  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    int size = primes.size();
    for (int i = 0; i < size; ++i) {
      int p = primes[i];
      if (p > n / 2) {
        break;
      }
      if (isPrime[n - p]) {
        kotae++;
      }
    }
    cout << kotae << endl;
  }

  return 0;
}