#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int MAXN = 51000;
bitset<MAXN> isPrime;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  isPrime.set();
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i <= MAXN; i++) { // sieve prime numbers up to sqrt(MAXN)
    if (isPrime[i]) {
      for (int j = i * i; j <= MAXN; j += i) {
        isPrime[j] = false;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i <= MAXN; i++) { // store prime numbers in a vector
    if (isPrime[i])
      primes.push_back(i);
  }

  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; primes[i] <= n / 2; i++) { // iterate only up to n/2
      if (isPrime[n - primes[i]])
        kotae++;
    }
    cout << kotae << '\n';
  }
  return 0;
}