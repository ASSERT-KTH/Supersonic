#include <stdio.h>

int isprime1(int n) {
  if(n<=1){
      return 0;
  }
  if(n==2){
      return 1;
  }
  if(n%2==0){
      return 0;
  }
  int i;
  for (i = 3; i*i <= n; i+=2) {
    if (n % i == 0){
      return 0;
    }
  }
  return 1;
}

int main() {
  int n, p, q, i;
  scanf("%d", &n);
  while (n) {
    for (i = n; i >= 5; i--) {
      if (isprime1(i) == 1 && isprime1(i - 2) == 1) {
        p = i - 2;
        q = i;
        printf("%d %d\n", p, q);
        break;
      }
    }
    scanf("%d", &n);
  }
  return 0;
}
