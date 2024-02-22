#include <algorithm>
#include <iostream>
#include <vector>

using uint = unsigned int;

class Graph {
  const uint n_;
  std::vector<uint> g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(n_ * n_, INFINIT), INFINIT(100000 * (n_ - 1) + 1) {}

  uint *operator[](uint i) const { return &g_[n_ * i]; }

  void dijkstra(uint *dist) {
    std::fill_n(dist, n_, INFINIT);
    std::vector<bool> visited(n_, false);
    auto i = 0u;
    visited[i] = true;
    dist[i] = 0u;
    for (auto n = 0u; n < n_ - 1; ++n) {
      auto cur_min = INFINIT;
      auto es = (*this)[i];
      auto base_dist = dist[i];
      for (auto j = 0u; j < n_; ++j) {
        if (visited[j])
          continue;
        dist[j] = std::min(dist[j], base_dist + es[j]);
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
  uint n;
  std::cin >> n;
  Graph g(n);
  uint u, k, c, v;
  for (auto i = 0u; i < n; ++i) {
    std::cin >> u >> k;
    for (auto j = 0u; j < k; ++j) {
      std::cin >> c >> v;
      g[u][c] = v;
    }
  }
  std::vector<uint> dist(n, g.INFINIT);
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::cout << i << " " << dist[i] << "\n";
  }
}