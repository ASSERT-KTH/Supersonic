#include <stdio.h>
int main(void) {
  int n, k, i;
  while (1) {
    scanf("%d", &n);
    if (n == 0)
      break;
    int s = n;
    int flg = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0) {
        s = s - 1;
      } else if (k >= 2) {
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