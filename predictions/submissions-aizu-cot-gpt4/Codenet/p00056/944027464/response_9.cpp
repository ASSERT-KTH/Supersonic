#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  vector<char> isPrime(51000 + 1, false);
  isPrime[2] = true;
  vector<int> primes;
  primes.push_back(2);
  for (int i = 3; i < 51000; i += 2) {
    if (!isPrime[i]) {
      primes.push_back(i);
      for (int j = i * i; j < 51000; j += i) {
        isPrime[j] = true;
      }
    }
  }
  int n, size = primes.size();
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; i < size; i++) {
      if (primes[i] > n / 2)
        break;
      if (!isPrime[n - primes[i]])
        kotae++;
    }
    cout << kotae << "\n";
  }
  return 0;
}