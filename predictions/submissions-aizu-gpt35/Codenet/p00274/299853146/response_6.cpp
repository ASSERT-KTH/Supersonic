#include <stdio.h>

int main(void) {
  int h, s = 0, n, k, t = 0, i, flg;
  while (scanf("%d", &n) == 1 && n != 0) {
    s = n;
    flg = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0) {
        s--;
      } else if (k >= 2) {
        flg = 1;
      }
    }
    printf("%s%d\n", flg ? "" : "NA ", s);
  }
  return 0;
}