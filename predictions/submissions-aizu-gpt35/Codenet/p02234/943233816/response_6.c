#include <stdio.h>
#define INF 100000000
int m[101][101];
int p[101];
int matrixChainOrder(int pl) {
  int n = pl - 1;
  for (int i = 1; i <= n; i++) {
    m[i][i] = 0;
  }
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = INF;
      for (int k = i; k < j; k++) {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (m[i][j] > q)
          m[i][j] = q;
      }
    }
  }
  return m[1][n];
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    if (i < n - 1)
      scanf("%d", &p[i+1]);
  }
  int x = matrixChainOrder(n + 1);
  printf("%d\n", x);
  return 0;
}