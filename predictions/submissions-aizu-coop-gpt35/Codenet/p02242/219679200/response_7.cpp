#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#pragma GCC optimize("O2")

using uint = unsigned int;

struct Edge {
  uint target;
  uint weight;
};

struct Node {
  uint index;
  uint distance;

  bool operator<(const Node& other) const {
    return distance > other.distance;
  }
};

class Graph {
  const uint n_;
  std::vector<uint> g_;
  const uint INFINIT;

public:
  Graph(uint n)
      : n_(n), g_(n_ * n_, INFINIT), INFINIT(100000 * (n_ - 1) + 1) {}

  uint* operator[](uint i) {
    return &g_[n_ * i];
  }

  void dijkstra(uint* dist) {
    std::fill_n(dist, n_, INFINIT);
    std::priority_queue<Node> pq;
    auto i = 0u;
    dist[i] = 0u;
    pq.push(Node{i, dist[i]});
    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      if (dist[cur.index] < cur.distance)
        continue;
      auto es = (*this)[cur.index];
      for (auto j = 0u; j < n_; ++j) {
        auto new_dist = cur.distance + es[j];
        if (dist[j] > new_dist) {
          dist[j] = new_dist;
          pq.push(Node{j, dist[j]});
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
      g[u].push_back(Edge{c, v});
    }
  }
  uint dist[n];
  g.dijkstra(dist);
  for (auto i = 0u; i < n; ++i) {
    std::printf("%u %u\n", i, dist[i]);
  }
}