#include <stdio.h>
#include <math.h>

int isprime1(int n) {
  int i;
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, p = -1, q = -1, i, found = 0;
  scanf("%d", &n);
  
  while (1) {
    if (n == 0)
      break;
    for (i = n; i >= 5; i--) {
      if (isprime1(i) == 1 && isprime1(i - 2) == 1) {
        p = i - 2;
        q = i;
        found = 1;
        break;
      }
    }
    if (found) {
      printf("%d %d\n", p, q);
    } else {
      printf("No prime pair found\n");
    }
    scanf("%d", &n);
    found = 0;
    p = -1;
    q = -1;
  }
  
  return 0;
}