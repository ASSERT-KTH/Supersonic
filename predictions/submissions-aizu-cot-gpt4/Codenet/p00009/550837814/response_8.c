#include <math.h>
#include <stdio.h>

#define MAX 1000000
#define SQRT_MAX 1000

int main() {
  int i, j;

  unsigned char num[MAX / 8 + 1] = {0};
  int sqrt_max = sqrt(MAX);

  for (i = 2; i < sqrt_max; i++) {
    if (!(num[i / 8] & (1 << (i % 8)))) {
      for (j = i * i; j < MAX; j += i)
        num[j / 8] |= 1 << (j % 8);
    }
  }

  for (i = 3; i < MAX; i++)
    if (!(num[i / 8] & (1 << (i % 8))))
      num[i / 8] += num[(i - 1) / 8];

  int n;
  while ((n = getchar()) != EOF) {
    n -= '0';
    printf("%d\n", num[n / 8] & (1 << (n % 8)) ? 0 : 1);
  }

  return 0;
}