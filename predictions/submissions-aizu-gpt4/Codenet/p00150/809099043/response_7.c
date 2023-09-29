#include <stdio.h>
#include <math.h>

bool isprime1(int n) {
  if(n<=1) return false;
  if(n==2) return true;
  if(n%2==0) return false;
  int m=sqrt(n);
  for (int i=3; i<=m; i+=2) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  int n, p, q;
  while (scanf("%d", &n), n) {
    for (int i = n; i >= 5; --i) {
      if (isprime1(i) && isprime1(i - 2)) {
        p = i - 2;
        q = i;
        break;
      }
    }
    printf("%d %d\n", p, q);
  }
  return 0;
}