#include <stdio.h>
#include <math.h>

int isprime1(int n) {
  if(n < 2)
    return 0;
  if(n == 2)
    return 1;
  if(n % 2 == 0)
    return 0;
  for (int i = 3; i <= sqrt(n); i+=2) { 
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, p, q, i, prev_prime;
  scanf("%d", &n);
  while (n != 0) {
    prev_prime = isprime1(n);
    for (i = n; i >= 5; i--) {
      if (prev_prime && isprime1(i - 2)) {
        p = i - 2;
        q = i;
        break;
      }
      prev_prime = isprime1(i - 2);
    }
    printf("%d %d\n", p, q);
    scanf("%d", &n);
  }
  return 0;
}