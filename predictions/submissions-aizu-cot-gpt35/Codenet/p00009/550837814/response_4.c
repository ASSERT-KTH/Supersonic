#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 1000000

int main() {
  int i, j, n;
  int num[MAX_N] = {0};

  // Set all elements of num to 1
  memset(num, 1, sizeof(num));

  num[0] = num[1] = 0;

  // Calculate the square root of MAX_N
  int sqrtN = sqrt(MAX_N);

  // Sieve of Eratosthenes algorithm
  for (i = 2; i < sqrtN; i++) {
    if (num[i] == 1) {
      for (j = i * i; j < MAX_N; j += i)
        num[j] = 0;
    }
  }

  // Calculate the cumulative sum
  for (i = 1; i < MAX_N - 1; i++) {
    num[i + 1] += num[i];
  }

  // Read integers until the end of input
  while (scanf("%d", &n) == 1) {
    printf("%d\n", num[n]);
  }

  return 0;
}