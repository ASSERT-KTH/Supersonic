#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

const int MAXN = 100005;
const int LOGN = 20;
int idx_in_path[MAXN];
std::pair<int, int> path[MAXN << 1];
std::vector<int> adjList[MAXN];
int path_size = 0;

void dfs(int u, int depth = 0) {
  idx_in_path[u] = path_size;
  path[path_size++] = {depth, u};

  for (const auto &v : adjList[u]) {
    dfs(v, depth + 1);
    path[path_size++] = {depth, u};
  }
}

std::pair<int, int> ST[LOGN][MAXN << 1];

void build(int n) {
  int h = static_cast<int>(ceil(log2(n + 1)));

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
  return std::min(ST[p][l], ST[p][r - (1 << p)]).second;
}

int main() {
  int num_nodes;
  scanf("%d", &num_nodes);

  for (int u = 0; u < num_nodes; u++) {
    int num_neighbors;
    scanf("%d", &num_neighbors);
    adjList[u].resize(num_neighbors);

    for (auto &v : adjList[u]) {
      scanf("%d", &v);
    }
  }

  dfs(0);
  build(path_size);

  int num_queries;
  scanf("%d", &num_queries);

  while (num_queries--) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", lca(u, v));
  }
  return 0;
}