#include <iostream>
#include <set>
#include <vector>
#define INF 1e9

int main() {
  int n, m, l, k, a, h, t1, t2, t3;
  while (std::cin >> n >> m >> l >> k >> a >> h, n) {
    std::set<int> rei;
    rei.insert(a), rei.insert(h);
    std::vector<std::vector<int>> b(n, std::vector<int>(n, INF));
    for (int i = 0; i < l; i++) {
      int re;
      std::cin >> re;
      rei.insert(re);
    }
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
    for (int i = 0; i < n; i++) {
      if (rei.count(i)) {
        for (int j = 0; j < n; j++) {
          if (rei.count(j) && b[i][j] <= m) {
            b[i][j] = b[j][i] = b[i][j];
          } else {
            b[i][j] = INF;
          }
        }
      }
    }
    for (int o = 0; o < n; o++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          b[i][j] = std::min(b[i][j], b[i][o] + b[o][j]);
        }
      }
    }
    if (b[a][h] >= INF)
      std::cout << "Help!" << std::endl;
    else if (b[a][h] < m)
      std::cout << b[a][h] << std::endl;
    else
      std::cout << b[a][h] * 2 - m << std::endl;
  }
  return 0;
}