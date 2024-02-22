#include <stdio.h>
int main(void) {
  int h, s = 0, n, k, flg;
  while (1) {
    flg = 0;
    scanf("%d", &n);
    if (n == 0)
      break;
    s = n;
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0) {
        s = s - 1;
      }
      if (k >= 2) {
        flg = 1;
        break;
      }
    }
    if (flg == 1) {
      printf("%d\n", s + 1);
    } else {
      puts("NA");
    }
  }
  return 0;
}