#include <vector>
#include <queue>
#include <limits>
#include <cstdio>

using uint = unsigned int;

class Graph {
  struct Edge {
    uint node, weight;
  };
  const uint n_;
  std::vector<std::vector<Edge>> g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(n), INFINIT(100000 * (n - 1) + 1) {}

  void add_edge(uint u, uint v, uint w) {
    g_[u].push_back({v, w});
  }

  void dijkstra(std::vector<uint>& dist) {
    dist.assign(n_, INFINIT);
    std::vector<bool> visited(n_, false);
    using pii = std::pair<uint, uint>;
    std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty()) {
      uint u = pq.top().second;
      pq.pop();
      if (visited[u])
        continue;
      visited[u] = true;
      for (const Edge& edge : g_[u]) {
        uint v = edge.node, w = edge.weight;
        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          pq.push({dist[v], v});
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
      g.add_edge(u, c, v);
    }
  }
  std::vector<uint> dist;
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}