#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
  vector<bool> isPrime(51000 + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= sqrt(51000); i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= 51000; j += i) {
        isPrime[j] = false;
      }
    }
  }
  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 2; i <= n / 2; i++) {
      if (isPrime[i] && isPrime[n - i])
        kotae++;
    }
    cout << kotae << endl;
  }
  return 0;
}