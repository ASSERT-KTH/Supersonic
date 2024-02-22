#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int limit = 51000;
  vector<bool> isPrime(limit + 1, true);
  isPrime[0] = isPrime[1] = false;
  
  for (int i = 2; i*i <= limit; i++) {
    if (isPrime[i]) {
      for (int j = i*i; j <= limit; j += i) {
        isPrime[j] = false;
      }
    }
  }

  int n;
  while (cin >> n && n != 0) {
    int count = 0;
    for (int i = 2; i <= n / 2; i++) {
      if (isPrime[i] && isPrime[n - i]) {
        count++;
      }
    }
    cout << count << endl;
  }
  return 0;
}