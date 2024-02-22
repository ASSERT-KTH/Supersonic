#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX_NUM 1000000

int main() {
  bool isPrime[MAX_NUM];
  int primeCount[MAX_NUM];
  int i, j, n;

  // Initialize isPrime array
  for (i = 2; i < MAX_NUM; i++) {
    isPrime[i] = true;
  }

  // Sieve of Eratosthenes algorithm
  for (i = 2; i <= sqrt(MAX_NUM); i++) {
    if (isPrime[i]) {
      for (j = i * i; j < MAX_NUM; j += i) {
        isPrime[j] = false;
      }
    }
  }

  // Calculate the prime count using a cumulative sum approach
  primeCount[0] = primeCount[1] = 0;
  for (i = 2; i < MAX_NUM; i++) {
    primeCount[i] = primeCount[i - 1] + isPrime[i];
  }

  // Read input numbers and print prime counts
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", primeCount[n]);
  }

  return 0;
}