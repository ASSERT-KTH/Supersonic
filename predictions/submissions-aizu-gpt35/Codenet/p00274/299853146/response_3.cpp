#include <stdio.h>
int main(void) {
  int h, s = 0, n, k, t = 0, i, flg;
  while (scanf("%d", &n) != EOF && n) {
    flg = s = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0)
        s--;
      if (k >= 2)
        flg = 1;
    }
    if (flg)
      printf("%d\n", s + 1);
    else
      puts("NA");
  }
  return 0;
}