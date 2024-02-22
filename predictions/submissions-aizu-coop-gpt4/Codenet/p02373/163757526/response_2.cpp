#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> ii;
typedef vector<int> vi;
const int MAXN = 100005;
const int LOGN = 20;
int idx_in_path[MAXN];
ii path[MAXN << 1];
vi adjList[MAXN];
int path_size = 0;

// DFS using iterative approach
void dfs(int u, int depth = 0) {
  stack<pair<int, int>> s;
  s.push({u, depth});
  while (!s.empty()) {
    tie(u, depth) = s.top(); s.pop();
    idx_in_path[u] = path_size;
    path[path_size++] = ii(depth, u);
    for (int v : adjList[u]) {
      s.push({v, depth + 1});
      path[path_size++] = ii(depth, u);
    }
  }
}

ii ST[LOGN][MAXN << 1];
// Building sparse table in a cache-friendly manner
void build(int n) {
  int h = ceil(log2(n + 1));
  for (int i = 0; i < n; i++)
    ST[0][i] = path[i];
  for (int j = 0; (1 << j) <= n; j++)
    for (int i = 0; i + (1 << j) <= n; i++)
      ST[j][i] = min(ST[j - 1][i], ST[j - 1][i + (1 << (j - 1))]);
}

// Caching the result of computation
int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;
  int p = 31 - __builtin_clz(r - l);
  ii min_val = min(ST[p][l], ST[p][r - (1 << p)]);
  return min_val.se;
}

int main() {
  int num_nodes;
  scanf("%d", &num_nodes);
  for (int u = 0; u < num_nodes; u++) {
    int num_neighbors;
    scanf("%d", &num_neighbors);
    // Preallocating space for vectors
    adjList[u].reserve(num_neighbors);
    for (int i = 0; i < num_neighbors; i++) {
      int v;
      scanf("%d", &v);
      adjList[u].push_back(v);
    }
  }
  dfs(0);
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