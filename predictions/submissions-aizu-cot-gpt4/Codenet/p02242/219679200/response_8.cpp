#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <memory>

using uint = unsigned int;

class Graph {
  const uint n_;
  std::unique_ptr<uint[]> g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(new uint[n_ * n_]), INFINIT(100000 * (n_ - 1) + 1) {
    std::fill_n(g_.get(), n_ * n_, INFINIT);
  }

  uint *operator[](uint i) const { return g_.get() + (n_ * i); }

  void dijkstra(std::vector<uint>& dist) {
    dist.assign(n_, INFINIT);
    std::vector<bool> visited(n_, false);
    dist[0] = 0u;
    std::priority_queue<std::pair<uint, uint>, std::vector<std::pair<uint, uint>>, std::greater<>> pq;
    pq.push({0u, 0u});
    while (!pq.empty()) {
      auto [base_dist, i] = pq.top();
      pq.pop();
      if (visited[i])
        continue;
      visited[i] = true;
      auto es = (*this)[i];
      for (auto j = 0u; j < n_; ++j) {
        if (!visited[j] && dist[j] > base_dist + es[j]) {
          dist[j] = base_dist + es[j];
          pq.push({dist[j], j});
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
  std::vector<uint> dist(n);
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}