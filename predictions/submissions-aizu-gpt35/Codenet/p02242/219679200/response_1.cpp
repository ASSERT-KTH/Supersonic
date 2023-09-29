#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using uint = unsigned int;

class Graph {
  const uint n_;
  std::vector<uint> g_;

public:
  Graph(uint n) : n_(n), g_(n_ * n_, 100000 * (n_ - 1) + 1) {}
  uint* operator[](uint i) { return g_.data() + (n_ * i); }
  void dijkstra(uint* dist) {
    std::fill_n(dist, n_, 100000 * (n_ - 1) + 1);
    std::vector<bool> visited(n_, false);
    auto i = 0u;
    visited[i] = true;
    dist[i] = 0u;
    std::priority_queue<std::pair<uint, uint>, std::vector<std::pair<uint, uint>>, std::greater<std::pair<uint, uint>>> pq;
    for (uint j = 0; j < n_; j++) {
      if (g_[i * n_ + j] != 100000 * (n_ - 1) + 1) {
        pq.push(std::make_pair(g_[i * n_ + j], j));
      }
    }
    while (!pq.empty()) {
      auto cur_min = pq.top().second;
      pq.pop();
      if (visited[cur_min])
        continue;
      visited[cur_min] = true;
      auto es = (*this)[cur_min];
      auto base_dist = dist[cur_min];
      for (uint j = 0; j < n_; j++) {
        if (visited[j])
          continue;
        uint new_dist = base_dist + es[j];
        if (new_dist < dist[j]) {
          dist[j] = new_dist;
          pq.push(std::make_pair(new_dist, j));
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
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}