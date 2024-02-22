#include <stdio.h>
#include <math.h>

int isprime(int n) {
  if (n < 2)
    return 0;
  if (n == 2)
    return 1;
  if (n % 2 == 0)
    return 0;
  
  int sqrt_n = (int) sqrt(n);
  for (int i = 3; i <= sqrt_n; i += 2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, p, q;
  
  scanf("%d", &n);
  while (n != 0) {
    for (int i = n; i >= 5; i -= 2) {
      if (isprime(i) && isprime(i - 2)) {
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