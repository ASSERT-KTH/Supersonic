#include <stdio.h>
int main() {
  int n, S[10000], q, T[500], i, j, cnt = 0, flag = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  scanf("%d", &q);
  for (j = 0; j < q; j++)
    scanf("%d", &T[j]);
  for (i = 0; i < q; i++) {
    flag = 0;
    for (j = 0; j < n; j++) {
      if (T[i] == S[j]) {
        cnt++;
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      break;
    }
  }
  printf("%d\n", cnt);
  return 0;
}