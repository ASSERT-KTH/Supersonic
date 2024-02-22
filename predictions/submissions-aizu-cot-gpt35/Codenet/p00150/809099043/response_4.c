#include <stdio.h>
#include <math.h>

int isprime1(int n) {
  int i;
  if (n == 2) {
    return 1;
  }
  if (n % 2 == 0 || n == 1) {
    return 0;
  }
  for (i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n, p, q, i;
  scanf("%d", &n);
  while (n != 0) {
    for (i = n; i >= 3; i -= 2) {
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