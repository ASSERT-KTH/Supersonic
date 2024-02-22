#include <stdio.h>
int main(void) {
  int n, s = 0, flg;
  while (1) {
    flg = 0;
    scanf("%d", &n);
    if (n == 0)
      break;
    s = n - 1;
    for (int i = 0; i < n; i++) {
      int k;
      scanf("%d", &k);
      if (k != 1) {
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