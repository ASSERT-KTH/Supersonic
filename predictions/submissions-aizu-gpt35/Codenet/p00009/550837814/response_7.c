#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 1000000

bool is_prime[MAX_NUM];

int main() {
  int i, j, n;
  int num_primes = 0;

  for (i = 2; i < MAX_NUM; i++) {
    is_prime[i] = true;
  }

  for (i = 2; i <= sqrt(MAX_NUM); i++) {
    if (is_prime[i]) {
      for (j = i * i; j < MAX_NUM; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for (i = 2; i < MAX_NUM; i++) {
    if (is_prime[i]) {
      num_primes++;
    }
  }

  int num[num_primes];
  int index = 0;
  for (i = 2; i < MAX_NUM; i++) {
    if (is_prime[i]) {
      num[index++] = i;
    }
  }

  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n - 1]);
  }

  return 0;
}