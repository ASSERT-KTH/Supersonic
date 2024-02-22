#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void) {
  int limit = 51000;
  vector<char> isPrime(limit + 1, true);
  isPrime[0] = isPrime[1] = false;
  int sqrt_limit = sqrt(limit);
  
  for (int i = 2; i <= sqrt_limit; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= limit; j += i) {
        isPrime[j] = false;
      }
    }
  }
  
  vector<int> primes;
  if(limit >= 2) primes.push_back(2);
  for (int i = 3; i <= limit; i += 2) {
    if (isPrime[i])
      primes.push_back(i);
  }

  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    for (int i = 0; i < primes.size() && primes[i] <= n / 2; i++) {
      if (isPrime[n - primes[i]])
        kotae++;
    }
    cout << kotae << endl;
  }
  return 0;
}