#include <stdio.h>
#include <math.h>

int isprime1(int n) {
  if (n <= 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  for (int i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, p, q, i, prev_prime = 0;
  scanf("%d", &n);
  while (1) {
    if (n == 0)
      break;
    if (n % 2 == 0) --n;  // make n odd
    for (i = n; i >= 5; i -= 2) {
      if (isprime1(i) && prev_prime) {
        p = i - 2;
        q = i;
        break;
      }
      prev_prime = isprime1(i - 2);
    }
    printf("%d %d\n", p, q);
    scanf("%d", &n);
  }
  return 0;
}