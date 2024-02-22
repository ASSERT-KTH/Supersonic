#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define MAX 51000

bitset<MAX + 1> isPrime;
vector<int> primes;

void generatePrimes() {
  isPrime.set(); // set all bits to 1
  isPrime[0] = isPrime[1] = false;
  primes.push_back(2);
  for (int i = 4; i <= MAX; i += 2)
    isPrime[i] = false;
  
  for (int i = 3; i * i <= MAX; i += 2) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= MAX; j += i) {
        isPrime[j] = false;
      }
    }
  }
  for(int i = primes.back() + 2; i <= MAX; i += 2) {
    if(isPrime[i]) primes.push_back(i);
  }
}

int main(void) {
  generatePrimes();
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