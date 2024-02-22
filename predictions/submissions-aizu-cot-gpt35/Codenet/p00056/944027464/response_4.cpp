#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  const int MAX_NUMBER = 51000;
  vector<bool> isPrime(MAX_NUMBER + 1, true);
  
  for (int i = 3; i * i <= MAX_NUMBER; i += 2) {
    if (isPrime[i]) {
      for (int j = i * i; j <= MAX_NUMBER; j += i) {
        isPrime[j] = false;
      }
    }
  }
  
  vector<int> primes;
  primes.push_back(2);
  for (int i = 3; i <= MAX_NUMBER; i += 2) {
    if (isPrime[i])
      primes.push_back(i);
  }
  
  int n;
  while (cin >> n && n != 0) {
    int kotae = 0;
    int sqrtN = sqrt(n);
    for (int i = 0; i < primes.size() && primes[i] <= sqrtN; i++) {
      if (isPrime[n - primes[i]])
        kotae++;
    }
    cout << kotae << endl;
  }
  
  return 0;
}