#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using uint = unsigned int;

class Graph {
  const uint n_;
  std::vector<uint> g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(n_ * n_), INFINIT(100000 * (n_ - 1) + 1) {
    std::fill(g_.begin(), g_.end(), INFINIT);
  }
  
  uint *operator[](uint i) { return &g_[n_ * i]; }
  
  void dijkstra(std::vector<uint>& dist) {
    std::fill(dist.begin(), dist.end(), INFINIT);
    std::vector<bool> visited(n_, false);
    dist[0] = 0u;
    std::priority_queue<std::pair<uint,uint>, std::vector<std::pair<uint,uint>>, std::greater<std::pair<uint,uint>>> pq;
    pq.push({0, 0});
    
    while(!pq.empty()) {
      uint i = pq.top().second;
      pq.pop();
      
      if(visited[i])
        continue;
      
      visited[i] = true;
      uint* es = (*this)[i];
      
      for(uint j = 0; j < n_; ++j) {
        if(!visited[j] && dist[j] > dist[i] + es[j]) {
          dist[j] = dist[i] + es[j];
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
    std::scanf("%u%u", &u, &k);
    for (auto j = 0u; j < k; ++j) {
      std::scanf("%u%u", &c, &v);
      g[u][c] = v;
    }
  }
  std::vector<uint> dist(n);
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}