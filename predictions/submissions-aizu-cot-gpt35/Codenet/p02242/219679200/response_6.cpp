#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using uint = unsigned int;

class Graph {
  const uint n_;
  std::vector<uint> g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_((n_ * n_), INFINIT), INFINIT(100000 * (n_ - 1) + 1) {}

  uint *operator[](uint i) { return &g_[(n_ * i)]; }

  void dijkstra(uint *dist) {
    std::fill_n(dist, n_, INFINIT);
    std::vector<bool> visited(n_, false);
    auto i = 0u;
    visited[i] = true;
    dist[i] = 0u;

    struct Vertex {
      uint index;
      uint distance;

      bool operator<(const Vertex &other) const {
        return distance > other.distance;
      }
    };

    std::priority_queue<Vertex> pq;
    pq.push({i, dist[i]});

    while (!pq.empty()) {
      auto current = pq.top();
      pq.pop();

      if (visited[current.index])
        continue;

      visited[current.index] = true;
      dist[current.index] = current.distance;

      auto es = (*this)[current.index];
      for (auto j = 0u; j < n_; ++j) {
        if (visited[j])
          continue;

        auto new_distance = current.distance + es[j];
        if (new_distance < dist[j]) {
          dist[j] = new_distance;
          pq.push({j, new_distance});
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
  g.dijkstra(dist.data());
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}