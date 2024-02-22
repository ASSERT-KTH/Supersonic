#include <stdio.h>
#include <limits.h>

int m[101];

int matrixChainOrder(int pl) {
  int i, j, l, k, q;
  for (i = 1; i < pl; i++) {
    m[i] = 0;
  }
  for (l = 2; l < pl; l++) {
    for (i = 1; i < pl - l + 1; i++) {
      j = i + l - 1;
      m[i] = INT_MAX;
      for (k = i; k < j; k++) {
        q = m[i] + m[k + 1] + p[i - 1] * p[k] * p[j];
        if (m[i] > q)
          m[i] = q;
      }
    }
  }
  return m[1];
}

int main() {
  int pl, i;
  scanf("%d", &pl);
  int p[pl];
  for (i = 0; i < pl; i++) {
    scanf("%d", &p[i]);
  }
  printf("%d\n", matrixChainOrder(pl));
  return 0;
}