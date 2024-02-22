#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using uint = unsigned int;

class Graph {
  const uint n_;
  std::vector<std::vector<uint>> g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(n, std::vector<uint>(n, INFINIT)), INFINIT(100000 * (n - 1) + 1) {}

  uint *operator[](uint i) const { return g_[i].data(); }

  void dijkstra(uint *dist) {
    std::fill_n(dist, n_, INFINIT);
    std::vector<bool> visited(n_, false);
    auto i = 0u;
    visited[i] = true;
    dist[i] = 0u;
    std::priority_queue<std::pair<uint, uint>, std::vector<std::pair<uint, uint>>,
                        std::greater<std::pair<uint, uint>>>
        pq;
    pq.push(std::make_pair(0u, i));
    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      auto cur_dist = cur.first;
      auto cur_node = cur.second;
      if (visited[cur_node])
        continue;
      visited[cur_node] = true;
      dist[cur_node] = cur_dist;
      for (auto j = 0u; j < n_; ++j) {
        if (visited[j])
          continue;
        auto new_dist = cur_dist + (*this)[cur_node][j];
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
  std::vector<uint> dist(n);
  g.dijkstra(dist.data());
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}