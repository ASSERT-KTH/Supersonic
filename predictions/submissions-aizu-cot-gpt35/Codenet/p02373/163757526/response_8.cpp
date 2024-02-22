#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;

const int MAXN = 100005;
const int LOGN = 20;

int idx_in_path[MAXN];
vector<ii> path;
vector<int> adjList[MAXN];
int path_size = 0;

void dfs(int u, int& depth) {
  idx_in_path[u] = path_size;
  path.emplace_back(depth, u);
  path_size++;

  for (int v : adjList[u]) {
    depth++;
    dfs(v, depth);
    path.emplace_back(depth, u);
    path_size++;
    depth--;
  }
}

vector<vector<ii>> ST;

void build(int n) {
  int h = log2(n) + 1;
  ST.resize(h, vector<ii>(n));

  for (int i = 0; i < n; i++)
    ST[0][i] = path[i];

  for (int i = 1; i < h; i++) {
    for (int j = 0; j + (1 << i) <= n; j++) {
      ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + (1 << (i - 1))]);
    }
  }
}

int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;

  int p = 31 - __builtin_clz(r - l);
  return min(ST[p][l], ST[p][r - (1 << p)]).second;
}

int main() {
  int num_nodes;
  scanf("%d", &num_nodes);

  for (int u = 0; u < num_nodes; u++) {
    int num_neighbors;
    scanf("%d", &num_neighbors);

    for (int i = 0; i < num_neighbors; i++) {
      int v;
      scanf("%d", &v);
      adjList[u].emplace_back(v);
    }
  }

  int depth = 0;
  dfs(0, depth);
  build(path_size);

  int num_queries;
  scanf("%d", &num_queries);

  for (int i = 0; i < num_queries; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", lca(u, v));
  }

  return 0;
}