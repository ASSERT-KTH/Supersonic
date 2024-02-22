#include <stdio.h>
#include <math.h>

int isprime1(int n) {
  if(n<2)
    return 0;
  if(n<4)
    return 1;
  if(n%2==0)
    return 0;
  int i;
  for (i = 3; i <= sqrt(n); i+=2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, i;
  int smallestPrime = 5;
  while (scanf("%d", &n) != EOF && n >= 5) {
    int p, q;
    for (i = (n < smallestPrime ? n : smallestPrime); i >= 5; i--) {
      if (isprime1(i) && isprime1(i - 2)) {
        p = i - 2;
        q = i;
        smallestPrime = p;
        break;
      }
    }
    printf("%d %d\n", p, q);
  }
  return 0;
}