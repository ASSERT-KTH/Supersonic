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
      else if (k >= 2) { // Use else-if instead of if for better performance
        flg = 1;
      }
    }
    printf("%s\n", flg ? "" : "NA"); // Use ternary operator instead of if-else
    t = 0;
  }
  return 0;
}