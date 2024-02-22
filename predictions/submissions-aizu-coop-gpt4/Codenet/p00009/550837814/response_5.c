#include <math.h>
#include <stdio.h>
#include <stdbool.h> // Include boolean data type

int main() {
  int i, j, n;
  bool num[1000000]; // Replace integer array with boolean array
  int primeCount[1000000]; // Store prime counts
  int sqrtLimit = sqrt(1000000); // Calculate square root once

  // Initialize both arrays
  for (i = 0; i < 1000000; i++) {
    num[i] = true;
    primeCount[i] = i > 1 ? 1 : 0;
  }

  // Sieve of Eratosthenes and accumulate prime counts
  for (i = 2; i < sqrtLimit; i++) {
    if (num[i]) {
      for (j = i * i; j < 1000000; j += i)
        num[j] = false;
      primeCount[i] = primeCount[i - 1] + 1;
    }
    else {
      primeCount[i] = primeCount[i - 1];
    }
  }

  // For numbers greater than sqrtLimit, only accumulate prime counts
  for (i = sqrtLimit; i < 1000000; i++) {
    primeCount[i] = primeCount[i - 1] + (num[i] ? 1 : 0);
  }

  while (scanf("%d", &n) != EOF) {
    printf("%d\n", primeCount[n]);
  }

  return 0;
}