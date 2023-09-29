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
  int hash[10000] = {0};
  for (i = 0; i < n; i++) {
    hash[S[i]]++;
  }
  for (i = 0; i < q; i++) {
    if (hash[T[i]] > 0) {
      C++;
    }
  }
  printf("%d\n", C);
  return 0;
}