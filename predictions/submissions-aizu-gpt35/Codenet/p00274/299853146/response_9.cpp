#include <stdio.h>
int main(void) {
  int h, s = 0, n, k, t = 0, i, flg;
  while (1) {
    flg = 0;
    scanf("%d", &n);
    if (n == 0)
      break;
    s = n;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0) {
        s--;
      }
      if (k >= 2) {
        flg = 1;
      }
    }
    if (flg == 1) {
      printf("%d\n", s + 1);
    } else {
      printf("NA\n");
    }
  }
  return 0;
}
