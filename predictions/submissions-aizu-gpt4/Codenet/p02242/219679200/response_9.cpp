#include <vector>
#include <queue>
#include <cstdio>
#include <limits>

using uint = unsigned int;

class Graph {
  const uint n_;
  using Edge = std::pair<uint, uint>;
  std::vector<std::vector<Edge>> adjList_;

public:
  Graph(uint n)
      : n_(n), adjList_(n) {}
  
  void addEdge(uint u, uint v, uint c) {
    adjList_[u].emplace_back(v, c);
  }

  void dijkstra(std::vector<uint>& dist) {
    dist.assign(n_, std::numeric_limits<uint>::max());
    std::vector<bool> visited(n_, false);
    using Pair = std::pair<uint, uint>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;

    dist[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()) {
      uint u = pq.top().second;
      pq.pop();

      if (visited[u]) continue;
      visited[u] = true;

      for (const auto& edge : adjList_[u]) {
        uint v = edge.first, weight = edge.second;
        if (dist[u] + weight < dist[v]) {
          dist[v] = dist[u] + weight;
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
    while (k--) {
      std::scanf("%u %u", &c, &v);
      g.addEdge(u, c, v);
    }
  }
  std::vector<uint> dist;
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
  return 0;
}