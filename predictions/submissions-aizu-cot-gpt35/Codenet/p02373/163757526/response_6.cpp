#include <cstdio>

const int MAXN = 100005;
const int LOGN = 20;

struct Node {
  int depth;
  int node;
};

int idx_in_path[MAXN];
Node path[MAXN << 1];
int path_size = 0;
std::vector<int> adjList[MAXN];
Node ST[LOGN][MAXN << 1];

void dfs(int u, int depth = 0) {
  idx_in_path[u] = path_size;
  path[path_size++] = {depth, u};
  for (int v : adjList[u]) {
    dfs(v, depth + 1);
    path[path_size++] = {depth, u};
  }
}

void build(int n) {
  int h = 32 - __builtin_clz(n);
  for (int i = 0; i < n; i++)
    ST[0][i] = path[i];
  for (int i = 1; i < h; i++)
    for (int j = 0; j + (1 << i) <= n; j++)
      ST[i][j] = std::min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
}

int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    std::swap(l, r);
  r++;
  int p = 31 - __builtin_clz(r - l);
  return std::min(ST[p][l], ST[p][r - (1 << p)]).node;
}

int main() {
  int num_nodes;
  std::scanf("%d", &num_nodes);

  char buffer[4096];
  for (int u = 0; u < num_nodes; u++) {
    int num_neighbors;
    std::fgets(buffer, sizeof(buffer), stdin);
    std::sscanf(buffer, "%d", &num_neighbors);
    for (int i = 0; i < num_neighbors; i++) {
      int v;
      std::sscanf(buffer, "%d", &v);
      adjList[u].emplace_back(v);
    }
  }

  dfs(0);
  build(path_size);

  int num_queries;
  std::scanf("%d", &num_queries);
  for (int i = 0; i < num_queries; i++) {
    int u, v;
    std::scanf("%d%d", &u, &v);
    std::printf("%d\n", lca(u, v));
  }

  return 0;
}