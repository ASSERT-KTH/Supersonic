#include <algorithm>
#include <cstdio>
#include <vector>
using uint = unsigned int;
class Graph {
  const uint n_;
  std::vector<uint> g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(n*n_, 100000 * (n - 1) + 1), INFINIT(100000 * (n - 1) + 1) {
  }
  uint *operator[](uint i) { return &g_[n_ * i]; }
  void dijkstra(std::vector<uint>& dist) {
    dist.assign(n_, INFINIT);
    std::vector<bool> visited(n_, false);
    auto i = 0u;
    visited[i] = true;
    dist[i] = 0u;
    for (auto n = 0u; n < n_ - 1; ++n) {
      auto base_dist = dist[i];
      for (auto j = 0u; j < n_; ++j) {
        if (!visited[j])
          dist[j] = std::min(dist[j], base_dist + g_[i*n_ + j]);
      }
      auto min_itr = std::min_element(dist.begin(), dist.end());
      i = std::distance(dist.begin(), min_itr);
      visited[i] = true;
      dist[i] = *min_itr;
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
  std::vector<uint> dist;
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}