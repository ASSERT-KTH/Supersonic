#include <iostream>
#define INF 100000000
int m[101][101];
int p[101];

int matrixChainOrder(int pl) {
  const int n = pl - 1;
  for (int i = 1; i <= n; i++) {
    m[i][i] = 0;
  }
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      const int j = i + l - 1;
      m[i][j] = INF;
      for (int k = i; k < j; k++) {
        if (m[i][j] > m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j])
          m[i][j] = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
      }
    }
  }
  return m[1][n];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, x, k;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
    if (i < n - 1)
      std::cin >> k;
  }
  std::cin >> p[n];
  x = matrixChainOrder(n + 1);
  std::cout << x << "\n";
  return 0;
}