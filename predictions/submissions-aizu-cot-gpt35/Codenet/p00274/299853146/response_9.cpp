#include <stdio.h>

int main(void) {
  int s, n, k;

  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;

    s = n;
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0) {
        s--;
      } else if (k >= 2) {
        printf("%d\n", s + 1);
        goto next;
      }
    }

    printf("NA\n");
  next:
    continue;
  }

  return 0;
}