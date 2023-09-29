#include <stdio.h>

int isprime1(int n) {
  if (n <= 2)
    return n == 2;
  if (n % 2 == 0)
    return 0;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, p, q, i;
  scanf("%d", &n);
  while (n != 0) {
    for (i = n; i >= 5; i -= 2) {
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