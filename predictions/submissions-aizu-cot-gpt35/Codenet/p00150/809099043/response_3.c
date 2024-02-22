#include <stdio.h>
#include <math.h>

int isprime1(int n) {
  if (n == 2 || n == 3)
    return 1;
  if (n % 2 == 0 || n % 3 == 0)
    return 0;
  int i = 5;
  int w = 2;
  while (i * i <= n) {
    if (n % i == 0)
      return 0;
    i += w;
    w = 6 - w;
  }
  return 1;
}

int main() {
  int n, p, q;
  scanf("%d", &n);
  while (n != 0) {
    for (int i = n - 2; i >= 5; i -= 2) {
      if (isprime1(i) && isprime1(i - 2)) {
        p = i - 2;
        q = i;
        printf("%d %d\n", p, q);
        break;
      }
    }
    scanf("%d", &n);
  }
  return 0;
}