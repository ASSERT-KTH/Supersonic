#include <stdio.h>
int main(void) {
  int s = 0, n, k, i, flg;
  while (1) {
    flg = 0;
    scanf("%d", &n);
    if (n == 0)
      break;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0) {
        s--;
      } else if (k >= 2) {
        flg = 1;
        break;
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