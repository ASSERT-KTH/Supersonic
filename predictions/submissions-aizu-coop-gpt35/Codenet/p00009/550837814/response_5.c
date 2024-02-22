#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NUM 1000000

int main() {
  int i, j;
  int n;
  bool is_prime[MAX_NUM];

  // Set all numbers as prime initially
  for (i = 0; i < MAX_NUM; i++) {
    is_prime[i] = true;
  }
  
  is_prime[0] = is_prime[1] = false;

  int sqrt_max_num = sqrt(MAX_NUM);

  // Mark multiples of prime numbers as non-prime
  for (i = 2; i < sqrt_max_num; i++) {
    if (is_prime[i]) {
      for (j = i * i; j < MAX_NUM; j += 2 * i) {
        is_prime[j] = false;
      }
    }
  }

  // Count the number of primes up to each index
  for (i = 1; i < MAX_NUM - 1; i++) {
    is_prime[i + 1] += is_prime[i];
  }

  // Read input numbers and print the corresponding count of primes
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", is_prime[n]);
  }
  
  return 0;
}