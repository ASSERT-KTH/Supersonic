#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using uint = unsigned int;

class Graph {
  const uint n_;
  std::vector<std::vector<uint>> g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(n_, std::vector<uint>(n_)), INFINIT(100000 * (n_ - 1) + 1) {
    for(auto& row : g_)
      std::fill(row.begin(), row.end(), INFINIT);
  }

  std::vector<uint>& operator[](uint i) { return g_[i]; }

  void dijkstra(std::vector<uint>& dist) {
    dist.assign(n_, INFINIT);
    std::vector<bool> visited(n_, false);
    dist[0] = 0u;

    using pii = std::pair<int, int>;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    pq.push({0, 0});

    while(!pq.empty()){
      int u = pq.top().second;
      pq.pop();

      visited[u] = true;

      for(uint v = 0; v < n_; ++v) {
        if(!visited[v] && g_[u][v] != INFINIT && dist[u] + g_[u][v] < dist[v]) {
          dist[v] = dist[u] + g_[u][v];
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
      g[u][c] = v;
    }
  }
  std::vector<uint> dist(n);
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}