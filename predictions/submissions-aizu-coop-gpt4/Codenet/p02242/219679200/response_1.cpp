#include <vector>
#include <queue>
#include <iostream>
#include <limits>

using uint = unsigned int;
constexpr uint INFINIT = std::numeric_limits<uint>::max();

struct Edge {
  uint to, cost;
};

using Graph = std::vector<std::vector<Edge>>;

void dijkstra(const Graph& graph, uint* dist, uint start) {
  std::fill(dist, dist + graph.size(), INFINIT);
  using P = std::pair<uint, uint>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> queue;
  dist[start] = 0;
  queue.push(P(0, start));

  while (!queue.empty()) {
    P p = queue.top();
    queue.pop();
    uint v = p.second;
    if (dist[v] < p.first) continue;
    for (const auto& edge : graph[v]) {
      if (dist[edge.to] > dist[v] + edge.cost) {
        dist[edge.to] = dist[v] + edge.cost;
        queue.push(P(dist[edge.to], edge.to));
      }
    }
  }
}

int main() {
  uint n;
  std::cin >> n;
  Graph graph(n);
  uint u, k, c, v;
  for (uint i = 0; i < n; ++i) {
    std::cin >> u >> k;
    for (uint j = 0; j < k; ++j) {
      std::cin >> c >> v;
      graph[u].push_back({c, v});
    }
  }
  uint dist[n];
  dijkstra(graph, dist, 0);
  for (uint i = 0; i < n; ++i) {
    std::cout << i << ' ' << dist[i] << '\n';
  }
  return 0;
}