#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
const int MAXN = 51000;
bitset<MAXN + 1> isPrime;
vector<int> primes;
int main(void) {
  isPrime.reset();
  isPrime[2] = true;
  for (int i = 3; i <= MAXN; i += 2) {
    isPrime[i] = true;
  }
  for (int i = 3; i * i <= MAXN; i += 2) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAXN; j += 2 * i)
        isPrime[j] = false;
    }
  }
  primes.reserve(5000);
  primes.push_back(2);
  for (int i = 3; i <= MAXN; i += 2) {
    if (isPrime[i])
      primes.push_back(i);
  }
  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; primes[i] <= n / 2; i++) {
      if (isPrime[n - primes[i]])
        kotae++;
    }
    cout << kotae << endl;
  }
  return 0;
}