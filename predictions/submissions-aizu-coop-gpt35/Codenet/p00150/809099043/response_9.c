#include <stdio.h>
#include <math.h>

int isprime(int n) {
  if (n <= 1)
    return 0;
    
  int i;
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, p, q, i;
  scanf("%d", &n);
  
  while (n != 0) {
    for (i = n-1; i >= 5; i--) {
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