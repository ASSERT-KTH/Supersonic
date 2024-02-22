#include <iostream>
#define MAX 999999

int num_prime[MAX + 1];

int main() {
  int n;

  // Calculate prime numbers using Sieve of Eratosthenes
  for (int i = 2; i < MAX + 1; ++i) {
    if (!num_prime[i]) {
      for (int j = i * 2; j < MAX + 1; j += i) {
        num_prime[j] = 1;
      }
    }
  }

  // Count the number of primes up to index i
  for (int i = 2; i < MAX + 1; ++i) {
    num_prime[i] += num_prime[i - 1];
  }

  while (std::cin >> n) {
    std::cout << num_prime[n] << std::endl;
  }

  return 0;
}