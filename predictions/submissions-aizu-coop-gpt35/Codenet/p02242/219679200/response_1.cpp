#include <algorithm>
#include <cstdio>
#include <vector>
#include <array>

class Graph {
  const uint n_;
  std::vector<std::vector<uint>> g_;
  static constexpr uint INFINIT = 100000;

public:
  Graph(uint n)
      : n_(n), g_(n_, std::vector<uint>(n_, INFINIT)) {}

  std::vector<uint>& operator[](uint i) { return g_[i]; }

  void dijkstra(std::array<uint, n>& dist) {
    std::array<bool, n> visited;
    std::fill(visited.begin(), visited.end(), false);
    auto i = 0u;
    visited[i] = true;
    dist[i] = 0u;
    for (auto n = 0u; n < n_ - 1; ++n) {
      auto cur_min = INFINIT;
      auto& es = g_[i];
      auto base_dist = dist[i];
      for (auto j = 0u; j < n_; ++j) {
        if (visited[j])
          continue;
        auto new_dist = base_dist + es[j];
        if (new_dist < dist[j]) {
          dist[j] = new_dist;
        }
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
  std::scanf("%u", &n);
  Graph g(n);
  uint u, k, c, v;
  for (auto i = 0u; i < n; ++i) {
    std::scanf("%u %u", &u, &k);
    for (auto j = 0u; j < k; ++j) {
      std::scanf("%u %u", &c, &v);
      g[u][c] = v;
    }
  }
  std::array<uint, n> dist;
  std::fill(dist.begin(), dist.end(), INFINIT);
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}