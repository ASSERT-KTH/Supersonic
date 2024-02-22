#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using uint = unsigned int;
using Node = std::pair<uint, uint>;

class Graph {
  const uint n_;
  std::vector<std::vector<Node>> g_;
  const uint INFINIT;

public:
  Graph(uint n)
    : n_(n), g_(n_), INFINIT(100000 * (n_ - 1) + 1) {}

  std::vector<Node>& operator[](uint i) { return g_[i]; }
  
  void dijkstra(std::vector<uint>& dist) {
    dist.assign(n_, INFINIT);
    std::vector<bool> visited(n_, false);
    dist[0] = 0;
    
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    pq.push({0, 0});
    
    while (!pq.empty()) {
      uint i = pq.top().second;
      pq.pop();
      
      if (visited[i]) continue;
      visited[i] = true;
      
      for (auto& adj : g_[i]) {
        uint j = adj.first, w = adj.second;
        if (!visited[j] && dist[i] + w < dist[j]) {
          dist[j] = dist[i] + w;
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
  
  for (uint i = 0; i < n; ++i) {
    uint u, k;
    std::scanf("%u %u", &u, &k);
    while (k--) {
      uint v, w;
      std::scanf("%u %u", &v, &w);
      g[u].push_back({v, w});
    }
  }
  
  std::vector<uint> dist;
  g.dijkstra(dist);
  for (uint i = 0; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}