#include <stdio.h>
int isprime2(int n) {
  int i;
  for (i = 2; i * i <= n; i++) {
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
    for (i = n; n >= 5; i--) {
      if (isprime2(i) == 1 && isprime2(i - 2) == 1) {
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
