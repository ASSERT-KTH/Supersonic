#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXN 1000000

int main() {
  int i, j;
  int n;
  bool num[MAXN] = {0};  // All elements are set to 0 initially
  int sqrtN = sqrt(MAXN);

  // Set all numbers from 2 to sqrt(MAXN) to 1
  for (i = 2; i <= sqrtN; i++) {
    num[i] = 1;
  }

  // Sieve of Eratosthenes
  for (i = 2; i <= sqrtN; i++) {
    if (num[i]) {
      for (j = i * i; j < MAXN; j += i)
        num[j] = 0;
    }
  }

  // Create prefix sum array
  for (i = 1; i < MAXN; i++) {
    num[i] += num[i - 1];
  }

  // Answer queries
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }

  return 0;
}