#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n = 51000;
  vector<bool> isPrime(n/2, true);
  for (int i = 3; i * i <= n; i += 2) {
    if (isPrime[i/2]) {
      for (int j = i * i; j <= n; j += 2*i) {
        isPrime[j/2] = false;
      }
    }
  }

  while (cin >> n && n != 0) {
    int count = 0;
    for (int i = 3; i <= n / 2; i += 2) {
      if(isPrime[i/2] && isPrime[(n - i)/2]) {
        count++;
      }
    }
    cout << count << endl;
  }

  return 0;
}