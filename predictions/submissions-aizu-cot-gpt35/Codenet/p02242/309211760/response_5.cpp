#include <iostream>
#include <vector>
#include <algorithm>

constexpr int MAX = 100;
constexpr int INFTY = (1 << 21);
constexpr int WHITE = 0;
constexpr int GRAY = 1;
constexpr int BLACK = 2;

int n;
std::vector<int> M;

void dijkstra() {
  std::vector<int> d(n, INFTY);
  std::vector<int> color(n, WHITE);
  d[0] = 0;
  color[0] = GRAY;

  while (true) {
    int minv = INFTY;
    int u = -1;
    for (int i = 0; i < n; i++) {
      if (minv > d[i] && color[i] != BLACK) {
        u = i;
        minv = d[i];
      }
    }
    if (u == -1)
      break;
    color[u] = BLACK;
    for (int v = 0; v < n; v++) {
      if (color[v] != BLACK && M[u * n + v] != INFTY) {
        if (d[v] > d[u] + M[u * n + v]) {
          d[v] = d[u] + M[u * n + v];
          color[v] = GRAY;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << '\n';
  }
}

int main() {
  std::cin >> n;
  M.resize(n * n, INFTY);
  std::fill(M.begin(), M.end(), INFTY);

  for (int i = 0; i < n; i++) {
    int u, k;
    std::cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v, c;
      std::cin >> v >> c;
      M[u * n + v] = c;
    }
  }

  dijkstra();

  return 0;
}