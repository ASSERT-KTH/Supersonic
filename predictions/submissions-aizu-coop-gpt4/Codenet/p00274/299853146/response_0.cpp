#include <stdio.h>

int main(void) {
  int n, k, i, flg;
  
  while (1) {
    flg = 0;
    
    // Validate input
    if(scanf("%d", &n) != 1)
      break;
      
    if (n == 0)
      break;
      
    for (i = 0; i < n; i++) {
      // Validate input
      if(scanf("%d", &k) != 1)
        break;
      
      if (k == 0) {
        n = n - 1;
      }
      else if (k >= 2) {
        flg = 1;
        break; // Early termination
      }
    }
    
    if (flg == 1) {
      printf("%d\n", n + 1);
    } else {
      printf("NA\n");
    }
  }
  
  return 0;
}