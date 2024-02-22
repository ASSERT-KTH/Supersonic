#include <stdio.h>
#include <math.h>

int isprime1(int n) {
  if (n < 2) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  int upperLimit = sqrt(n);
  for (int i = 3; i <= upperLimit; i += 2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, p, q;
  scanf("%d", &n);
  while (1) {
    if (n == 0)
      break;
    if (n % 2 == 0) n--; // ensure n is odd
    for (int i = n; i >= 5; i -= 2) {
      if (isprime1(i) == 1 && isprime1(i - 2) == 1) {
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