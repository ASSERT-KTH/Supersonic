#include <stdio.h>
int main() {
  int i, k, n, q, t, C = 0, S[100], T[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &T[i]);
  }
  for (k = 0; k < q; k++) {
    for (i = 0; i < n; i++) {
      if (S[i] == T[k]) {
        C++;
        break;
      }
    }
  }
  printf("%d\n", C);
  return 0;
}
