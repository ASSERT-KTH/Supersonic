#include <stdio.h>
int main(void) {
  int n, k, s, i, flg;
  while (scanf("%d", &n), n) {
    s = n;
    flg = 0;
    for (i = 0; i < n && scanf("%d", &k); i++) {
      s -= (k == 0);
      flg |= (k >= 2);
    }
    if (flg) printf("%d\n", s + 1);
    else printf("NA\n");
  }
  return 0;
}