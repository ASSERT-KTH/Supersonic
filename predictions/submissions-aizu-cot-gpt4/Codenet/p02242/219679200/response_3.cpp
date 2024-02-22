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
      : n_(n), g_(n_ * n_), INFINIT(100000 * (n_ - 1) + 1) {
    std::fill(g_.begin(), g_.end(), INFINIT);
  }
  uint *operator[](uint i) const { return g_.data() + (n_ * i); }
  void dijkstra(std::vector<uint>& dist) {
    dist.assign(n_, INFINIT);
    std::vector<bool> visited(n_, false);
    auto i = 0u;
    visited[i] = true;
    dist[i] = 0u;
    for (auto n = 0u; n < n_ - 1; ++n) {
      auto cur_min = INFINIT;
      const auto& es = (*this)[i];
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
  std::vector<uint> dist(n);
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::cout << i << " " << dist[i] << "\n";
  }
}