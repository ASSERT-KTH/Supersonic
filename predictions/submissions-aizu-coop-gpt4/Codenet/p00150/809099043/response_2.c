#include <stdio.h>
#include <math.h>

int isprime1(int n) {
  int i;
  int limit = sqrt(n);
  for (i = 2; i <= limit; i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, p, q, i;
  do {
    scanf("%d", &n);
    if (n == 0)
      break;
    for (i = n; n >= 5; i--) {
      int isPrime = isprime1(i);
      if (isPrime == 1 && isprime1(i - 2) == 1) {
        p = i - 2;
        q = i;
        break;
      }
    }
    printf("%d %d\n", p, q);
  } while (n != 0);

  return 0;
}