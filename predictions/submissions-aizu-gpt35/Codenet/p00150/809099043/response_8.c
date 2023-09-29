#include <stdio.h>
#include <stdbool.h>

bool isprime1(int n) {
  if(n<=1)
    return false;
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  int n, p, q, i;
  scanf("%d", &n);
  while (n != 0) {
    for (i = n; i >= 5; i--) {
      if (isprime1(i) && isprime1(i - 2)) {
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