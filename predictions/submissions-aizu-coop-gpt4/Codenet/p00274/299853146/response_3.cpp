#include <stdio.h>

int main(void) {
  int h, s = 0, n, k, t = 0, i, flg;
  
  while (1) {
    flg = 0;
    scanf("%d", &n);
    
    if (n == 0)
      break;
    
    s = 0;  // Reset s to 0 for each sequence
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      
      // Count non-zero numbers and check for numbers >= 2
      if (k != 0) {
        s++;
        if (k >= 2) {
          flg = 1;
        }
      }
    }
    
    if (flg == 1) {
      printf("%d\n", s + 1);
    } else {
      printf("NA\n");
    }
    t = 0;
  }
  
  return 0;
}