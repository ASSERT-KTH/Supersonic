#include <iostream>
#include <bitset>
#include <cmath>
#define MAX 999999
using namespace std;
int num_prime[MAX + 1];
bitset<MAX + 1> not_prime_flag;

void calculateNumPrimes(int n) {
  num_prime[n] = num_prime[n - 1] + !not_prime_flag[n];
}

int main() {
  ios_base::sync_with_stdio(false);
  int limit = sqrt(MAX + 1);
  for (int i = 2; i <= limit; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = i; i * j < MAX + 1; ++j) {
        not_prime_flag[i * j] = true;
      }
    }
  }
  for (int i = limit+1; i < MAX + 1; i++) {
    calculateNumPrimes(i);
  }
  int n;
  while (cin >> n) {
    calculateNumPrimes(n);
    cout << num_prime[n] << "\n";
  }
  return 0;
}