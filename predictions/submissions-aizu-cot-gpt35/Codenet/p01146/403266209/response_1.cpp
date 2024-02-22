#include <iostream>
#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max()

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (std::cin >> n >> m >> l >> k >> a >> h, n) {
    std::vector<bool> relevant(n, false);
    relevant[a] = true;
    relevant[h] = true;
    for (int i = 0; i < l; i++) {
      int re;
      std::cin >> re;
      relevant[re] = true;
    }
    std::vector<std::vector<int>> b(n, std::vector<int>(n, INF));
    for (int i = 0; i < k; i++) {
      std::cin >> t1 >> t2 >> t3;
      b[t1][t2] = b[t2][t1] = t3;
    }
    for (int o = 0; o < n; o++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          b[i][j] = std::min(b[i][j], b[i][o] + b[o][j]);
        }
      }
    }
    std::vector<std::vector<int>> x(n, std::vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
      if (relevant[i]) {
        for (int j = 0; j < n; j++) {
          if (relevant[j] && b[i][j] <= m) {
            x[i][j] = b[i][j];
          }
        }
      }
    }
    for (int o = 0; o < n; o++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          x[i][j] = std::min(x[i][j], x[i][o] + x[o][j]);
        }
      }
    }
    if (x[a][h] >= INF) {
      std::cout << "Help!" << std::endl;
    } else if (x[a][h] < m) {
      std::cout << x[a][h] << std::endl;
    } else {
      std::cout << x[a][h] * 2 - m << std::endl;
    }
  }
}