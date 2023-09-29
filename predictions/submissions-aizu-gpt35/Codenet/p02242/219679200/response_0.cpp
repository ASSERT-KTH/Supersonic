#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using uint = unsigned int;
class Graph {
  const uint n_;
  uint *const g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(new uint[(n_ * n_)]), INFINIT(100000 * (n_ - 1) + 1) {
    std::fill_n(g_, (n_ * n_), INFINIT);
  }
  ~Graph() { delete[] g_; }
  uint *operator[](uint i) const { return g_ + (n_ * i); }

  void dijkstra(uint *dist, uint start) {
    std::fill_n(dist, n_, INFINIT);
    dist[start] = 0;
    std::vector<char> visited(n_, false);
    for (auto i = 0u; i < n_; ++i) {
      uint cur = -1, cur_dist = INFINIT;
      for (auto j = 0u; j < n_; ++j) {
        if (!visited[j] && dist[j] < cur_dist) {
          cur_dist = dist[j];
          cur = j;
        }
      }
      if (cur == -1)
        break;
      visited[cur] = true;
      auto edges = (*this)[cur];
      for (auto j = 0u; j < n_; ++j) {
        auto new_dist = dist[cur] + edges[j];
        if (new_dist < dist[j]) {
          dist[j] = new_dist;
        }
      }
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
  for (auto i = 0u; i < n; ++i) {
    g.dijkstra(dist, i);
    for (auto j = 0u; j < n; ++j) {
      std::printf("%u %u\n", j, dist[j]);
    }
  }
}