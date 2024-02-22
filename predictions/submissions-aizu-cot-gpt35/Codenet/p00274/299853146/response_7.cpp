#include <stdio.h>

int main(void) {
  int n, k, hasNonZero;
  
  while (scanf("%d", &n) == 1 && n != 0) {
    hasNonZero = 0;
    
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      
      if (k > 0) {
        hasNonZero = 1;
      }
    }
    
    if (hasNonZero) {
      printf("%d\n", n);
    } else {
      printf("NA\n");
    }
  }
  
  return 0;
}