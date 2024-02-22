#include <iostream>
#include <bitset>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  bitset<51001> isPrime;
  isPrime.set();
  isPrime[0] = isPrime[1] = 0;
  for (int i = 4; i <= 51000; i += 2) {
    isPrime[i] = 0;
  }
  for (int i = 3; i * i <= 51000; i += 2) {
    if (isPrime[i]) {
      for (int j = i * i; j <= 51000; j += i) {
        isPrime[j] = 0;
      }
    }
  }
  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 2; i <= n / 2; ++i) {
      if (isPrime[i] && isPrime[n - i])
        kotae++;
    }
    cout << kotae << "\n";
  }
  return 0;
}