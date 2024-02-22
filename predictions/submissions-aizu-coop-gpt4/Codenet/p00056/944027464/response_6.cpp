#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  vector<bool> isPrime(51000 / 2 + 1, false);
  isPrime[1] = true;  // 2 is prime
  for (int i = 3; i < 51000; i += 2) {
    isPrime[i / 2] = true;
  }
  for (int i = 3; i * i < 51000; i += 2) {
    if(isPrime[i / 2]){
      for (int j = i * i; j < 51000; j += i) {
        isPrime[j / 2] = false;
      }
    }
  }
  vector<int> primes;
  primes.reserve(51000 / 2);  // Reserve space for half of the numbers
  primes.push_back(2);
  for (int i = 3; i < 51000; i += 2) {
    if (isPrime[i / 2])
      primes.push_back(i);
  }
  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; i < primes.size(); i++) {
      if (primes[i] <= n / 2) {
        if (isPrime[(n - primes[i]) / 2])
          kotae++;
      }
    }
    cout << kotae << endl;
  }
  return 0;
}