#include <vector>
#include <limits>
#include <iostream>

#define INF std::numeric_limits<int>::max()

std::vector<std::vector<int>> m(102, std::vector<int>(102, INF));
std::vector<int> p(102);

int matrixChainOrder(int pl) {
  int n = pl - 1;

  for (int i = 1; i <= n; i++) {
    m[i][i] = 0;
  }

  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;

      for (int k = i; k < j; k++) {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        m[i][j] = std::min(m[i][j], q);
      }
    }
  }

  return m[1][n];
}

int main() {
  int n, x, k;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
    if (i < n - 1)
      std::cin >> k;
  }
  std::cin >> p[n];
  x = matrixChainOrder(n + 1);
  std::cout << x << std::endl;
  return 0;
}