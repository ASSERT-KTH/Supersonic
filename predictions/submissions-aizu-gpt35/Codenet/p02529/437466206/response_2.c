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
  int hash[100] = {0};
  for (i = 0; i < n; i++) {
    hash[S[i]] = 1;
  }
  for (i = 0; i < q; i++) {
    if (hash[T[i]]) {
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}