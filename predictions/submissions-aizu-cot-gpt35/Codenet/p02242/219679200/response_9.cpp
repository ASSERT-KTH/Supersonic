#include <algorithm>
#include <cstdio>
#include <vector>
#include <limits>

using uint = unsigned int;

class Graph {
  const uint n_;
  std::vector<uint> g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(n_ * n_, std::numeric_limits<uint>::max()), INFINIT(std::numeric_limits<uint>::max()) {}

  uint* operator[](uint i) const { return g_.data() + (n_ * i); }

  void dijkstra(uint* dist) {
    std::fill_n(dist, n_, INFINIT);
    std::vector<bool> visited(n_, false);
    uint i = 0u;
    visited[i] = true;
    dist[i] = 0u;

    for (uint n = 0u; n < n_ - 1; ++n) {
      uint cur_min = INFINIT;
      uint* es = (*this)[i];
      uint base_dist = dist[i];

      for (uint j = 0u; j < n_; ++j) {
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
  std::scanf("%u", &n);
  Graph g(n);
  uint u, k, c, v;

  for (uint i = 0u; i < n; ++i) {
    std::scanf("%u %u", &u, &k);

    for (uint j = 0u; j < k; ++j) {
      std::scanf("%u %u", &c, &v);
      g[u][c] = v;
    }
  }

  std::vector<uint> dist(n);
  g.dijkstra(dist);

  for (uint i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}