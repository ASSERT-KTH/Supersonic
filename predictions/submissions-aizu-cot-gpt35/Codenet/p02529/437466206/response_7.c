#include <stdio.h>

#define MAX_N 100

int main() {
  int i, n, q, t, C = 0, S[MAX_N], element;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &element);
    S[element] = 1;
  }

  scanf("%d", &q);

  for (i = 0; i < q; i++) {
    scanf("%d", &element);
    if (S[element] == 1) {
      C++;
    }
  }

  printf("%d\n", C);

  return 0;
}