#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;

int main() {
  const int limit = 51000;
  bitset<limit + 1> isPrime;
  isPrime.set();
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= limit; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= limit; j += i) {
        isPrime[j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i <= limit; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    int left = 0, right = primes.size() - 1;
    while (left <= right) {
      int sum = primes[left] + primes[right];
      if (sum == n) {
        kotae++;
        left++;
        right--;
      } else if (sum < n) {
        left++;
      } else {
        right--;
      }
    }
    cout << kotae << endl;
  }

  return 0;
}