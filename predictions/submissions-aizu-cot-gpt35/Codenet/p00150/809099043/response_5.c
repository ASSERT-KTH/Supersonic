#include <stdio.h>
#include <math.h>

int isprime1(int n) {
  int i;
  if (n <= 1)
    return 0;
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, p = 0, q = 0, i;
  scanf("%d", &n);
  for (i = n; i >= 5; i -= 2) {
    if (isprime1(i) && isprime1(i - 2)) {
      p = i - 2;
      q = i;
      break;
    }
  }
  printf("%d %d\n", p, q);
  scanf("%d", &n);
  return 0;
}