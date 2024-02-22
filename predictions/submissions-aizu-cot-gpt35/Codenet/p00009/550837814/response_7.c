#include <stdio.h>

int main() {
  int i, j;
  int n;
  int num[1000];
  
  for (i = 0; i < 1000; i++) {
    num[i] = 1;
  }
  
  num[0] = num[1] = 0;
  
  int sqrt_limit = (int)sqrt(1000);
  for (i = 2; i <= sqrt_limit; i++) {
    if (num[i] == 1) {
      for (j = i * i; j < 1000; j += i) {
        num[j] = 0;
      }
    }
  }
  
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num[n]);
  }
  
  return 0;
}