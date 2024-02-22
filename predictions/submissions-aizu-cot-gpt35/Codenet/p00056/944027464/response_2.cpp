#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  vector<char> isPrime(51000 + 1, false);
  isPrime[2] = true;

  for (int i = 3; i < 51000; i += 2) {
    isPrime[i] = true;
  }

  for (int i = 3; i < 51000; i += 2) {
    if (isPrime[i]) {
      for (int j = i + i; j < 51000; j += i) {
        isPrime[j] = false;
      }
    }
  }

  vector<int> primes;
  primes.push_back(2);

  for (int i = 3; i < 51000; i += 2) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    int maxSize = n / 2;
    int left = 0;
    int right = primes.size() - 1;
    int lastIndex = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (primes[mid] <= maxSize) {
        lastIndex = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    for (int i = 0; i <= lastIndex; i++) {
      if (isPrime[n - primes[i]]) {
        kotae++;
      }
    }

    cout << kotae << endl;
  }

  return 0;
}