#include <queue>
#include <vector>
#include <cstdio>

using uint = unsigned int;
const uint INFINIT = 100000 * 100 + 1;

struct Edge {
  uint to, cost;
};

typedef std::pair<uint, uint> P;  // Pair of minimum distance and vertex

class Graph {
  uint n_;
  std::vector<std::vector<Edge>> g_;

public:
  Graph(uint n) : n_(n), g_(n_) {}
  
  void add_edge(uint u, uint c, uint v) {
    g_[u].push_back((Edge){c, v});
  }

  void dijkstra(uint *dist) {
    std::priority_queue<P, std::vector<P>, std::greater<P>> queue;
    fill(dist, dist + n_, INFINIT);
    dist[0] = 0;
    queue.push(P(0, 0));

    while (!queue.empty()) {
      P p = queue.top();
      queue.pop();
      uint v = p.second;
      if (dist[v] < p.first) continue;
      for (uint i = 0; i < g_[v].size(); i++) {
        Edge e = g_[v][i];
        if (dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
          queue.push(P(dist[e.to], e.to));
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
  for (uint i = 0; i < n; ++i) {
    std::scanf("%u %u", &u, &k);
    for (uint j = 0; j < k; ++j) {
      std::scanf("%u %u", &c, &v);
      g.add_edge(u, c, v);
    }
  }
  uint dist[n];
  g.dijkstra(dist);
  for (uint i = 0; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}