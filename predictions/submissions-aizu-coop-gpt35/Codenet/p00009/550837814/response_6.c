#include <stdio.h>
#include <stdlib.h>

int main() {
  int i, j, count = 0;
  int n;
  int *num;
  
  // Find the number of primes
  for (i = 2; i < 1000000; i++) {
    int isPrime = 1;
    for (j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        isPrime = 0;
        break;
      }
    }
    if (isPrime) {
      count++;
    }
  }
  
  // Allocate the num array
  num = (int*) malloc(count * sizeof(int));
  
  // Sieve of Eratosthenes
  for (i = 0; i < count; i++) {
    num[i] = 1;
  }
  
  for (i = 2; i * i < 1000000; i++) {
    if (num[i]) {
      for (j = i * i; j < 1000000; j += i) {
        num[j] = 0;
      }
    }
  }
  
  // Calculate cumulative sum
  for (i = 1; i < count; i++) {
    num[i] += num[i - 1];
  }
  
  // Read input and print the result
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }
  
  // Free memory
  free(num);
  
  return 0;
}