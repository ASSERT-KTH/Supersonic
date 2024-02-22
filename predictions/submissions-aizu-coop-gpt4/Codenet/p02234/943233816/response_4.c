#include <stdio.h>
#define INF 100000000

int m[101*101];
int p[101];

int matrixChainOrder(int pl) {
  int n = pl - 1;
  for (int i = 1; i <= n; i++) {
    m[i * n + i] = 0;
  }
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      int q = m[i * n + i] + m[(i + 1) * n + j] + p[i - 1] * p[i] * p[j];
      m[i * n + j] = q;
      for (int k = i + 1; k < j; k++) {
        int temp = m[i * n + k] + m[(k + 1) * n + j] + p[i - 1] * p[k] * p[j];
        if (q > temp)
          q = temp;
      }
      m[i * n + j] = q;
    }
  }
  return m[n];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    if (i < n - 1) {
      int k;
      scanf("%d", &k);
    }
  }
  scanf("%d", &p[n]);
  printf("%d\n", matrixChainOrder(n + 1));
  return 0;
}