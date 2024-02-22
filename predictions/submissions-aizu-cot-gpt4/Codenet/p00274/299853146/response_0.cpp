#include <stdio.h>
int main(void) {
  int n, k, i;
  bool hasTwoOrMore;
  while (1) {
    hasTwoOrMore = false;
    scanf("%d", &n);
    if (n == 0)
      break;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0) {
        --n;
      }
      if (k >= 2) {
        hasTwoOrMore = true;
      }
    }
    if (hasTwoOrMore) {
      printf("%d\n", n + 1);
    } else {
      printf("NA\n");
    }
  }
  return 0;
}