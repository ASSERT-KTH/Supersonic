#include <algorithm>
#include <cstdio>
#include <cstring>

using uint = unsigned int;

class Graph {
  const uint n_;
  uint **g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(new uint *[n_]), INFINIT(100000 * (n_ - 1) + 1) {
    for (uint i = 0; i < n_; ++i) {
      g_[i] = new uint[n_];
      memset(g_[i], INFINIT, n_ * sizeof(uint));
    }
  }

  ~Graph() {
    for (uint i = 0; i < n_; ++i) {
      delete[] g_[i];
    }
    delete[] g_;
  }

  uint *operator[](uint i) const { return g_[i]; }

  void dijkstra(const uint *const dist) {
    bool *visited = new bool[n_];
    memset(visited, false, n_ * sizeof(bool));

    uint i = 0;
    visited[i] = true;
    uint *es = (*this)[i];
    uint base_dist = dist[i];

    for (uint n = 0; n < n_ - 1; ++n) {
      uint cur_min = INFINIT;
      for (uint j = 0; j < n_; ++j) {
        if (visited[j])
          continue;
        uint new_dist = base_dist + es[j];
        if (dist[j] > new_dist) {
          dist[j] = new_dist;
        }
        if (cur_min > dist[j]) {
          cur_min = dist[j];
          i = j;
          es = (*this)[i];
          base_dist = dist[i];
        }
      }
      visited[i] = true;
    }

    delete[] visited;
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
      g[u][c] = v;
    }
  }
  uint *dist = new uint[n];
  memset(dist, g.INFINIT, n * sizeof(uint));
  g.dijkstra(dist);
  for (uint i = 0; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
  delete[] dist;
}