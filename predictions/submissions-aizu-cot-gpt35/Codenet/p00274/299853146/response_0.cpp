#include <stdio.h>

int main(void) {
  int n, k, i, flg;
  
  do {
    flg = 0;
    scanf("%d", &n);
    if (n == 0)
      break;
    
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0)
        n--;
      if (k >= 2)
        flg = 1;
    }
    
    if (flg)
      printf("%d\n", n);
    else
      printf("NA\n");
      
  } while (n != 0);
  
  return 0;
}