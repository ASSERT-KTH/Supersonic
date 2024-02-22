#include <stdio.h>

int main(void) {
  int s = 0, n, k, flg;

  while (scanf("%d", &n) && n != 0) {
    s = n;
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0) {
        s--;
      } else {
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