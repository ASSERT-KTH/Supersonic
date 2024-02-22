#include <algorithm>
#include <cstdio>
using uint = unsigned int;
class Graph {
  const uint n_;
  uint *const g_;
  const uint INFINIT;
  bool *visited;  // moved to class scope

public:
  Graph(uint n)
      : n_(n), g_(new uint[(n_ * n_)]), INFINIT(100000 * (n_ - 1) + 1), visited(new bool[n_]) {
    std::fill(g_, g_ + (n_ * n_), INFINIT);
    std::fill(visited, visited + n_, false);
  }
  ~Graph() {
    delete[] g_;
    delete[] visited;
  }
  uint *operator[](uint i) const { return g_ + (n_ * i); }
  void dijkstra(uint *dist) {
    std::fill(dist, dist + n_, INFINIT);
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
        auto temp = base_dist + es[j];  // store in a temporary variable
        dist[j] = std::min(dist[j], temp);
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
  uint dist[n];
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}