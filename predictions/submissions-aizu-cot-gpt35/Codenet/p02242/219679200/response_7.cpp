#include <algorithm>
#include <iostream>
#include <vector>

class Graph {
  const int n_;
  std::vector<std::vector<int>> g_;
  const int INFINIT;

public:
  Graph(int n)
      : n_(n), g_(n, std::vector<int>(n, INFINIT)), INFINIT(100000 * (n - 1) + 1) {}

  std::vector<int>& operator[](int i) { return g_[i]; }

  void dijkstra(std::vector<int>& dist) {
    std::vector<bool> visited(n_, false);
    int i = 0;
    visited[i] = true;
    dist[i] = 0;

    int n = n_ - 1;
    while (n--) {
      int cur_min = INFINIT;
      int base_dist = dist[i];

      for (int j = 0; j < n_; ++j) {
        if (visited[j])
          continue;
        dist[j] = std::min(dist[j], base_dist + g_[i][j]);
        if (cur_min > dist[j]) {
          cur_min = dist[j];
          i = j;
        }
      }

      visited[i] = true;
      dist[i] = cur_min;
    }
  }
};

int main() {
  int n;
  std::cin >> n;
  Graph g(n);

  int u, k, c, v;
  for (int i = 0; i < n; ++i) {
    std::cin >> u >> k;
    for (int j = 0; j < k; ++j) {
      std::cin >> c >> v;
      g[u][c] = v;
    }
  }

  std::vector<int> dist(n, g.INFINIT);
  g.dijkstra(dist);

  for (int i = 0; i < n; ++i) {
    std::cout << i << " " << dist[i] << "\n";
  }

  return 0;
}