#include <stdio.h>

int main(void) {
  int h, s, n, k, i;

  while (scanf("%d", &n) && n != 0) {
    s = n;

    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      
      if (k == 0) {
        s--;
      } else if (k >= 2) {
        printf("%d\n", s + 1);
        break;
      }
    }
    
    if (k < 2) {
      printf("NA\n");
    }
  }

  return 0;
}