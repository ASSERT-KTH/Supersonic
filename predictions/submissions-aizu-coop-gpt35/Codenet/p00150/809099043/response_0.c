#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX 1000000

bool isprime[MAX];

void calculatePrimes() {
  int i, j;
  for (i = 0; i < MAX; i++) {
    isprime[i] = true;
  }
  isprime[0] = false;
  isprime[1] = false;

  for (i = 4; i < MAX; i += 2) {
    isprime[i] = false;
  }

  int sqrtMax = sqrt(MAX);
  for (i = 3; i <= sqrtMax; i += 2) {
    if (isprime[i]) {
      for (j = i * i; j < MAX; j += 2 * i) {
        isprime[j] = false;
      }
    }
  }
}

int main() {
  int n, p, q, i;
  calculatePrimes();
  scanf("%d", &n);

  while (n != 0) {
    for (i = n; i >= 5; i--) {
      if (isprime[i] && isprime[i - 2]) {
        p = i - 2;
        q = i;
        break;
      }
    }
    printf("%d %d\n", p, q);
    scanf("%d", &n);
  }

  return 0;
}