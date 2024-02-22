#include <stdio.h>
int main(void) {
  int n, s;
  while (1) {
    int k, i, flg = 0;
    scanf("%d", &n);
    if (n == 0)
      break;
    s = n;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (!k) s--;
      if (k >= 2) flg = 1;
    }
    if (flg) printf("%d\n", s + 1);
    else printf("NA\n");
  }
  return 0;
}