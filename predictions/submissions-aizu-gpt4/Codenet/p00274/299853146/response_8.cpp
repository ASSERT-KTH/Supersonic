#include <stdio.h>
int main(void) {
  int n, k, count, i, flag;
  while (1) {
    flag = 0;
    count = 0;
    if(scanf("%d", &n), n==0)
      break;
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k != 0) {
        count++;
        if (k >= 2) {
          flag = 1;
        }
      }
    }
    printf(flag? "%d\n":"NA\n", count + 1);
  }
  return 0;
}