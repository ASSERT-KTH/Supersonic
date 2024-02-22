#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
  vector<bool> isPrime(51000 + 1, false);
  isPrime[2] = true;
  for (int i = 3; i < 51000; i += 2) {
    isPrime[i] = true;
  }

  int limit = sqrt(51000);
  for (int i = 3; i <= limit; i += 2) {
    if (isPrime[i]) {
      for (int j = i*i; j < 51000; j += i) {
        isPrime[j] = false;
      }
    }
  }

  int n;
  while (cin >> n && n != 0) {
    int count = 0;
    for (int i = 2; i <= n / 2; ++i) {
      if (isPrime[i] && isPrime[n - i]) {
        count++;
      }
    }
    cout << count << endl;
  }
  return 0;
}