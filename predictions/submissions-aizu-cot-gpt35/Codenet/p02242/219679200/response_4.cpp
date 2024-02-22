#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

class Graph {
  const unsigned int n_;
  std::vector<unsigned int> g_;
  const unsigned int INFINIT;

public:
  Graph(unsigned int n)
      : n_(n), g_((n_ * n_), INFINIT), INFINIT(100000 * (n_ - 1) + 1) {}

  unsigned int* operator[](unsigned int i) { return g_.data() + (n_ * i); }

  void dijkstra(unsigned int* dist) {
    std::memset(dist, INFINIT, n_ * sizeof(unsigned int));
    bool visited[n_];
    std::memset(visited, false, n_ * sizeof(bool));
    unsigned int i = 0u;
    visited[i] = true;
    dist[i] = 0u;
    for (unsigned int n = 0u; n < n_ - 1; ++n) {
      unsigned int cur_min = INFINIT;
      unsigned int* es = (*this)[i];
      unsigned int base_dist = dist[i];
      for (unsigned int j = 0u; j < n_; ++j) {
        if (visited[j])
          continue;
        dist[j] = std::min(dist[j], base_dist + es[j]);
        if (cur_min > dist[j]) {
          cur_min = dist[j];
          i = j;
        }
      }
      visited[i] = true;
      dist[i] = cur_min;
    }
  }
};

int main() {
  unsigned int n;
  std::cin >> n;
  Graph g(n);
  unsigned int u, k, c, v;
  for (unsigned int i = 0u; i < n; ++i) {
    std::cin >> u >> k;
    for (unsigned int j = 0u; j < k; ++j) {
      std::cin >> c >> v;
      g[u][c] = v;
    }
  }
  std::vector<unsigned int> dist(n);
  g.dijkstra(dist.data());
  for (unsigned int i = 0u; i < n; ++i) {
    std::cout << i << " " << dist[i] << "\n";
  }
}