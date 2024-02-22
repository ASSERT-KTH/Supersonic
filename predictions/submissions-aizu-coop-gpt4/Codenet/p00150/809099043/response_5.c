#include <stdio.h>
#include <math.h>

int isprime1(int n) {
  if (n < 2) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  int root = sqrt(n);
  for (int i = 3; i <= root; i += 2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, p, q, i;
  while (scanf("%d", &n) == 1 && n != 0) {
    for (i = n % 2 == 0 ? n - 1 : n; i >= 5; i -= 2) {
      if (isprime1(i) && isprime1(i - 2)) {
        p = i - 2;
        q = i;
        break;
      }
    }
    printf("%d %d\n", p, q);
  }
  return 0;
}