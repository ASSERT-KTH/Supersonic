#include <iostream>
#define MAX 999999
using namespace std;
bool not_prime_flag[MAX + 1];

int main() {
  int n;
  
  // Sieve algorithm with optimized inner loop.
  for (int i = 2; i * i <= MAX; ++i) {
    if (!not_prime_flag[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        not_prime_flag[j] = true;
      }
    }
  }
  
  // Calculate count of primes for each input number.
  while (cin >> n) {
    int count = 0;
    for (int i = 2; i <= n; ++i) {
      if (!not_prime_flag[i]) {
        ++count;
      }
    }
    cout << count << endl;
  }
  
  return 0;
}