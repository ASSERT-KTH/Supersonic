#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  const int MAX_N = 51000;
  vector<bool> isPrime(MAX_N, false);
  vector<int> primes;
  for (int i = 2; i < MAX_N; i++) {
    if (!isPrime[i]) {
      primes.push_back(i);
      for (int j = i + i; j < MAX_N; j += i) {
        isPrime[j] = true;
      }
    }
  }
  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; primes[i] <= n / 2; i++) {
      if (!isPrime[n - primes[i]]) {
        kotae++;
      }
    }
    cout << kotae << endl;
  }
  return 0;
}