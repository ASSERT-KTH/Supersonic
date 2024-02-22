#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  vector<int> isPrime(51000 + 1, false);
  isPrime[2] = true;
  for (int i = 3; i < 51000; i += 2) {
    isPrime[i] = true;
  }
  for (int i = 3; i*i < 51000; i += 2) {
    if (isPrime[i]) {
      for (int j = i * i; j < 51000; j += i) {
        isPrime[j] = false;
      }
    }
  }
  vector<int> primes;
  primes.reserve(51000/2); // Assuming half of the numbers are prime for upper limit
  primes.push_back(2);
  for (int i = 3; i < 51000; i += 2) {
    if (isPrime[i])
      primes.push_back(i);
  }
  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    int i = 0, j = primes.size() - 1;
    while (i <= j) {
      if (primes[i] + primes[j] > n) {
        j--;
      } else if (primes[i] + primes[j] < n) {
        i++;
      } else {
        kotae++;
        i++;
        j--;
      }
    }
    cout << kotae << endl;
  }
  return 0;
}