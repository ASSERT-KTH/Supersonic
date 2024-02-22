#include <iostream>
#include <vector>
#include <queue>
#define INF (1 << 29)
#define max_n 10000

struct edge {
  int to, cap, rev;
};

struct node_t {
  // implementation of node_t remains the same
};

node_t *expose(node_t *x) {
  // implementation of expose remains the same
}

// other helper functions remain the same

std::vector<edge> g[max_n];

void add_edge(int from, int to, int cap) {
  g[from].emplace_back((edge){to, cap, g[to].size()});
  g[to].emplace_back((edge){from, 0, g[from].size() - 1});
}

int dist[max_n];

bool bfs(int s, int t) {
  // implementation of bfs remains the same
}

int n, ptr[max_n];
node_t *nodes[max_n];
std::vector<int> lists[max_n];

bool pour(int id, int i) {
  // implementation of pour remains the same
}

int max_flow(int S, int T) {
  // implementation of max_flow remains the same
}

int main(void) {
  int e, a, b, c;
  std::cin >> n >> e;
  for (int i = 0; i < e; i++) {
    std::cin >> a >> b >> c;
    add_edge(a, b, c);
  }
  std::cout << max_flow(0, n - 1) << "\n";
  return 0;
}