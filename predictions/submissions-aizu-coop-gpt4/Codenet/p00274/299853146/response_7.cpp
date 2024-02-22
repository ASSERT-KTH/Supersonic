#include <stdio.h>
int main(void) {
  int n, k, i, flag;
  while (1) {
    flag = 0;
    scanf("%d", &n);
    if (n == 0)
      break;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0) {
        n--;
      } else if (k >= 2) {
        flag = 1;
      }
    }
    if (flag) {
      printf("%d\n", n + 1);
    } else {
      printf("NA\n");
    }
  }
  return 0;
}