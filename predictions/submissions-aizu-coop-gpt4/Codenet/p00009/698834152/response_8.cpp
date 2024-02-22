#include <iostream>
#include <cmath>
#define MAX 999999

using namespace std;

int num_prime[MAX + 1];
bool not_prime_flag[MAX + 1];

int main() {
  int n;
  int limit = sqrt(MAX); // Only iterate till the square root of MAX
  for (int i = 2; i <= limit; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = i * i; j <= MAX; j += i) { // Start loop from 'i*i'
        not_prime_flag[j] = true;
      }
    }
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }
  // Compute the remaining primes
  for (int i = limit + 1; i <= MAX; ++i) {
    num_prime[i] = num_prime[i - 1] + !not_prime_flag[i];
  }
  
  while (cin >> n) {
    cout << num_prime[n] << endl;
  }
  return 0;
}