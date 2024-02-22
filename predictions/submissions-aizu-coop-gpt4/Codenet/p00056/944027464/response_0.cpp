#include <iostream>
#include <bitset>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  bitset<51000 + 1> isPrime;
  isPrime[2] = true;
  for (int i = 3; i <= 51000; i += 2) {
    isPrime[i] = true;
  }
  for (int i = 3; i * i <= 51000; i += 2) {
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
    cout << kotae << '\n';
  }
  return 0;
}