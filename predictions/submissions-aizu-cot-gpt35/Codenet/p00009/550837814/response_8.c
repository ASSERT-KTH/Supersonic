#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
  int i, j;
  int n;
  int num[100000];
  bool isPrime[1000000];

  // Use Sieve of Eratosthenes to generate prime numbers
  for (i = 0; i < 1000000; i++) {
    isPrime[i] = true;
  }
  isPrime[0] = isPrime[1] = false;
  for (i = 2; i < sqrt(1000000); i++) {
    if (isPrime[i]) {
      for (j = i * i; j < 1000000; j += i) {
        isPrime[j] = false;
      }
    }
  }

  // Store the prime numbers in num array
  int count = 0;
  for (i = 0; i < 1000000; i++) {
    if (isPrime[i]) {
      num[count++] = i;
    }
  }

  int primeCount[100000];
  primeCount[0] = 0;

  // Calculate the cumulative sum of prime numbers
  for (i = 1; i < count; i++) {
    primeCount[i] = primeCount[i - 1] + 1;
  }

  while (scanf("%d", &n) != EOF) {
    printf("%d\n", primeCount[n]);
  }

  return 0;
}