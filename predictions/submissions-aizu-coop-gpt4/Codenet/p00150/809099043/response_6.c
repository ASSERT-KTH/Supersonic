#include <stdio.h>
#include <math.h>

int isprime1(int n, int* primeCache) {
  if (primeCache[n] != -1) {
    return primeCache[n];
  }

  if (n == 2) {
    primeCache[n] = 1;
    return 1;
  }

  if (n % 2 == 0) {
    primeCache[n] = 0;
    return 0;
  }

  int limit = sqrt(n);
  for (int i = 3; i <= limit; i += 2) {
    if (n % i == 0) {
      primeCache[n] = 0;
      return 0;
    }
  }

  primeCache[n] = 1;
  return 1;
}

int main() {
  int n, p, q, i, primeCache[10000];
  for (i = 0; i < 10000; i++) {
    primeCache[i] = -1;
  }

  while (scanf("%d", &n) == 1 && n != 0) {
    for (i = n; i >= 5; i -= 2) {
      if (isprime1(i, primeCache) && isprime1(i - 2, primeCache)) {
        p = i - 2;
        q = i;
        break;
      }
    }

    printf("%d %d\n", p, q);
  }

  return 0;
}