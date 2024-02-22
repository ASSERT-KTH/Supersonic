#include <stdio.h>
int main(void) {
  int n, k, s, i;
  while (1) {
    scanf("%d", &n);
    if (n == 0)
      break;
    s = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k != 0) {
        s++;
        if (k >= 2) {
          printf("%d\n", s + 1);
          break;
        }
      }
    }
    if (i == n) {
      printf("NA\n");
    }
  }
  return 0;
}