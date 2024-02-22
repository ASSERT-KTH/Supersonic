#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 1000000

int main() {
  int i, j, n;
  int num[MAX_N];
  memset(num, 1, sizeof(num)); // Initialize all elements to 1
  num[0] = num[1] = 0; // 0 and 1 are not prime

  int limit = sqrt(MAX_N); // Calculate sqrt once
  for (i = 2; i < limit; i++) {
    if (num[i] == 1) {
      for (j = i * i; j < MAX_N; j += i)
        num[j] = 0; // Mark non-prime numbers
    }
  }

  for (i = 1; i < MAX_N - 1; i++) {
    num[i + 1] += num[i]; // Calculate prefix sum
  }

  int ret;
  while ((ret = scanf("%d", &n)) != EOF && ret == 1) {
    printf("%d\n", num[n]); // Print sum of primes <= n
  }

  return 0;
}