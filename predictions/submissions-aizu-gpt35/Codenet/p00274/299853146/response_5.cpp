#include <stdio.h>

int main(void) {
  int h, s = 0, n, k, t = 0, i, flg;
  while (scanf("%d", &n) == 1 && n != 0) {
    flg = 0;
    s = n;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0) {
        s--;
      }
      if (k >= 2 && !flg) {
        flg = 1;
      }
    }
    if (flg) {
      printf("%d\n", s);
    } else {
      printf("NA\n");
    }
  }
  return 0;
}