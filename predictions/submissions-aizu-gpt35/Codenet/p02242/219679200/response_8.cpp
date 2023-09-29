#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using uint = unsigned int;

class Graph {
  const uint n_;
  std::vector<std::pair<uint, uint>> *const g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(new std::vector<std::pair<uint, uint>>[n_]), INFINIT(100000 * (n_ - 1) + 1) {
  }
  ~Graph() { delete[] g_; }
  std::vector<std::pair<uint, uint>> &operator[](uint i) const { return g_[i]; }
  void dijkstra(uint *dist) {
    std::fill_n(dist, n_, INFINIT);
    std::priority_queue<std::pair<uint, uint>, std::vector<std::pair<uint, uint>>, std::greater<std::pair<uint, uint>>> pq;
    pq.emplace(0u, 0u);
    while (!pq.empty()) {
      auto [d, u] = pq.top(); pq.pop();
      if (dist[u] != INFINIT) {
        continue;
      }
      dist[u] = d;
      for (auto [v, w] : g_[u]) {
        if (dist[v] == INFINIT) {
          pq.emplace(d + w, v);
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
      g[u].emplace_back(c, v);
    }
  }
  uint dist[n];
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}