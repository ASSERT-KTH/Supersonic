#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int s = 0, n, k, i;
  bool flg;
  
  while (1) {
    flg = false;
    scanf("%d", &n);
    if (n == 0)
      break;
    s = n;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0)
        s = s - 1;
      else if (k >= 2)
        flg = true;
    }
    if (flg)
      printf("%d\n", s + 1);
    else
      printf("NA\n");
  }
  return 0;
}