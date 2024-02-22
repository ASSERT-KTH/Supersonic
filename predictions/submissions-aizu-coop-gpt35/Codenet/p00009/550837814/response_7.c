#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the number of primes up to n
int calculatePrimes(int n) {
  int count = 0;
  int sqrtN = sqrt(n);

  // Dynamic allocation of the boolean array
  char* num = (char*)malloc((n + 1) * sizeof(char));

  // Initializing the array
  for (int i = 0; i <= n; i++) {
    num[i] = 1;
  }

  // Sieve of Eratosthenes algorithm
  for (int i = 2; i * i <= n; i++) {
    if (num[i] == 1) {
      for (int j = 2 * i; j <= n; j += i) {
        num[j] = 0;
      }
    }
  }

  // Counting the number of primes
  for (int i = 2; i <= n; i++) {
    if (num[i] == 1) {
      count++;
    }
  }

  // Freeing the allocated memory
  free(num);

  return count;
}

int main() {
  int n;

  while (scanf("%d", &n) != EOF) {
    int count = calculatePrimes(n);
    printf("%d\n", count);
  }

  return 0;
}