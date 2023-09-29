#include <stdio.h>
int isprime1(int n) {
  int i;
  for (i = 2; i < n; i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}
int main() {
  int n, p, q, i;
  scanf("%d", &n);
  while (1) {
    if (n == 0)
      break;
    for (i = n + 1; n >= 5; i--) {
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
