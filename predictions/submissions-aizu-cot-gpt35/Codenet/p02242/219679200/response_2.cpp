#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

using uint = unsigned int;

class Graph {
  const uint n_;
  uint *const g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(new uint[(n_ * n)]), INFINIT(100000 * (n_ - 1) + 1) {
    std::memset(g_, INFINIT, (n_ * n) * sizeof(uint));
  }
  ~Graph() { delete[] g_; }
  uint *operator[](uint i) const { return g_ + (n_ * i); }
  void dijkstra(uint *dist) {
    std::memset(dist, INFINIT, n_ * sizeof(uint));
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
        if (dist[j] > base_dist + es[j]) {
          dist[j] = base_dist + es[j];
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
  scanf("%u", &n);
  Graph g(n);
  uint u, k, c, v;
  for (auto i = 0u; i < n; ++i) {
    scanf("%u %u", &u, &k);
    for (auto j = 0u; j < k; ++j) {
      scanf("%u %u", &c, &v);
      g[u][c] = v;
    }
  }
  uint dist[n];
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    printf("%u %u\n", i, dist[i]);
  }
}