#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
  int i, j, n;
  int limit = sqrt(1000000);
  bool num[1000000];

  // Initialize all numbers as prime
  for (i = 0; i < 1000000; i++) {
    num[i] = true;
  }
  num[0] = num[1] = false;

  // Mark non-prime numbers
  for (i = 2; i <= limit; i++) {
    if (num[i]) {
      for (j = i * i; j < 1000000; j += i) {
        num[j] = false;
      }
    }
  }

  // Count primes till each number
  for (i = 2; i < 1000000; i++) {
    num[i] += num[i - 1];
  }

  // Input and output
  while (scanf("%d", &n) == 1) {
    printf("%d\n", num[n]);
  }

  return 0;
}