#include <stdio.h>

int main(void) {
  int n, k, i, flg;
  while (scanf("%d", &n), n) {
    int s = n;
    flg = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      s -= !k;
      flg |= k >= 2;
    }
    printf(flg ? "%d\n" : "NA\n", s + 1);
  }
  return 0;
}