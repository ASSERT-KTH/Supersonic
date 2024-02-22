#include <stdio.h>

int main(void) {
  int s = 0, n, k, i, zeros, hasGreater;
  while (1) {
    zeros = 0;
    hasGreater = 0;
    scanf("%d", &n);
    if (n == 0)
      break;
    s = n;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0) {
        zeros++;
      } else if (k >= 2) {
        hasGreater = 1;
      }
    }
    if (hasGreater) {
      printf("%d\n", s - zeros + 1);
    } else {
      printf("NA\n");
    }
  }
  return 0;
}