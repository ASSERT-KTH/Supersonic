#include <algorithm>
#include <cstdio>
#include <vector>

class Graph {
  const unsigned int n_;
  std::vector<unsigned int> g_;
  const unsigned int INFINIT;

public:
  Graph(unsigned int n)
      : n_(n), g_((n_ * n_), INFINIT), INFINIT(100000 * (n_ - 1) + 1) {}

  unsigned int *operator[](unsigned int i) { return &g_[n_ * i]; }

  void dijkstra(unsigned int *dist) {
    for (unsigned int i = 0; i < n_; ++i) {
      dist[i] = INFINIT;
    }

    bool visited[n_];
    for (unsigned int i = 0; i < n_; ++i) {
      visited[i] = false;
    }

    unsigned int i = 0;
    visited[i] = true;
    dist[i] = 0;

    for (unsigned int n = 0; n < n_ - 1; ++n) {
      unsigned int cur_min = INFINIT;
      unsigned int *es = (*this)[i];
      unsigned int base_dist = dist[i];

      for (unsigned int j = 0; j < n_; ++j) {
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
  scanf("%u", &n);

  Graph g(n);

  unsigned int u, k, c, v;
  for (unsigned int i = 0; i < n; ++i) {
    scanf("%u %u", &u, &k);

    for (unsigned int j = 0; j < k; ++j) {
      scanf("%u %u", &c, &v);
      g[u][c] = v;
    }
  }

  unsigned int dist[n];
  g.dijkstra(dist);

  for (unsigned int i = 0; i < n; ++i) {
    printf("%u %u\n", i, dist[i]);
  }

  return 0;
}