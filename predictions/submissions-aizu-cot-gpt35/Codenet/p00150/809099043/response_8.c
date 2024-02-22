#include <stdio.h>

int isprime1(int n) {
  if (n <= 1)
    return 0;
  if (n <= 3)
    return 1;
  if (n % 2 == 0 || n % 3 == 0)
    return 0;

  int i = 5;
  while (i * i <= n) {
    if (n % i == 0 || n % (i + 2) == 0)
      return 0;
    i += 6;
  }

  return 1;
}

int main() {
  int n, p = 0, q = 0;
  scanf("%d", &n);
  
  while (n != 0) {
    for (int i = n; i >= 5; i -= 2) {
      if (i % 2 != 0 && (i - 2) % 2 != 0) {
        if (isprime1(i) && isprime1(i - 2)) {
          p = i - 2;
          q = i;
          break;
        }
      }
    }
    printf("%d %d\n", p, q);
    scanf("%d", &n);
  }
  
  return 0;
}