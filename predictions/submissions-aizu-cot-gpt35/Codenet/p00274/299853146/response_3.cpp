#include <stdio.h>

int main(void) {
  int h, s = 0, n, k, flg = 0, zeroCount = 0;
  
  while (1) {
    scanf("%d", &n);
    
    if (n == 0)
      break;
    
    s = n;
    flg = 0;
    zeroCount = 0;
    
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      
      if (k == 0) {
        zeroCount++;
      }
      
      if (k >= 2) {
        flg = 1;
        break;
      }
    }
    
    if (flg == 1) {
      printf("%d\n", s - zeroCount + 1);
    } else {
      printf("NA\n");
    }
  }
  
  return 0;
}