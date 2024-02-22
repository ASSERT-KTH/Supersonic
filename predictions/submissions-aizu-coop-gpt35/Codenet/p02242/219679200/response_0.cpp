#include <algorithm>
#include <cstdio>
using uint = unsigned int;

class Graph {
  const uint n_;
  uint g_[n_ * n_];
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), INFINIT(100000 * (n_ - 1) + 1) {
    for (auto i = 0u; i < n_ * n_; ++i) {
      g_[i] = INFINIT;
    }
  }
  uint *operator[](uint i) const { return g_ + (n_ * i); }
  void dijkstra(uint *dist) {
    std::fill_n(dist, n_, INFINIT);
    uint visited[n_];
    std::fill_n(visited, n_, 0);
    auto i = 0u;
    visited[i] = 1;
    dist[i] = 0u;
    for (auto n = 0u; n < n_ - 1; ++n) {
      auto cur_min = INFINIT;
      auto es = (*this)[i];
      auto base_dist = dist[i];
      #pragma unroll
      for (auto j = 0u; j < n_; ++j) {
        if (visited[j])
          continue;
        dist[j] = std::min(dist[j], base_dist + es[j]);
        if (cur_min > dist[j]) {
          cur_min = dist[j];
          i = j;
        }
      }
      visited[i] = 1;
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
  uint dist[n];
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}