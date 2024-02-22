#include <stdio.h>
int main() {
  int T[500], S[10000], i, j, count = 0, n, q;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);
  scanf("%d", &q);
  for (j = 0; j < q; j++)
    scanf("%d", &T[j]);
  for (i = 0; i < q; i++) {
    for (j = 0; j < n; j++) {
      if (T[i] == S[j]) {
        count++;
        break;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
