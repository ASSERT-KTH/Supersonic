#include <stdio.h>
#include <math.h>

int isprime(int n) {
  if (n < 2)
    return 0;
  if (n == 2)
    return 1;
  if (n % 2 == 0)
    return 0;
  int limit = sqrt(n);
  for (int i = 3; i <= limit; i += 2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, p, q, i;
  scanf("%d", &n);
  while (n != 0) {
    int found = 0;
    for (i = n; i >= 5; i -= 2) {
      if (isprime(i) && isprime(i - 2)) {
        p = i - 2;
        q = i;
        found = 1;
        break;
      }
    }
    if (found) {
      printf("%d %d\n", p, q);
    }
    scanf("%d", &n);
  }
  return 0;
}