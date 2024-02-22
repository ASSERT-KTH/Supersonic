#include <iostream>
#include <vector>

class Graph {
  const unsigned int n_;
  std::vector<unsigned int> g_;
  const unsigned int INFINITY;

public:
  Graph(unsigned int n)
      : n_(n), g_((n_ * n_), INFINITY), INFINITY(100000 * (n_ - 1) + 1) {}

  unsigned int *operator[](unsigned int i) { return &g_[(n_ * i)]; }

  void dijkstra(unsigned int *dist) {
    std::fill_n(dist, n_, INFINITY);
    std::vector<bool> visited(n_, false);
    visited[0] = true;
    dist[0] = 0u;

    for (unsigned int n = 0u; n < n_ - 1; ++n) {
      unsigned int cur_min = INFINITY;
      auto &es = (*this)[n];

      for (unsigned int j = 0u; j < n_; ++j) {
        if (visited[j])
          continue;

        dist[j] = std::min(dist[j], dist[n] + es[j]);

        if (cur_min > dist[j]) {
          cur_min = dist[j];
        }
      }

      visited[cur_min] = true;
      dist[cur_min] = cur_min;
    }
  }
};

int main() {
  unsigned int n;
  std::cin >> n;

  Graph g(n);

  for (unsigned int i = 0u; i < n; ++i) {
    unsigned int u, k;
    std::cin >> u >> k;

    for (unsigned int j = 0u; j < k; ++j) {
      unsigned int c, v;
      std::cin >> c >> v;
      g[u][c] = v;
    }
  }

  std::vector<unsigned int> dist(n);
  g.dijkstra(dist);

  for (unsigned int i = 0u; i < n; ++i) {
    std::cout << i << " " << dist[i] << std::endl;
  }
}