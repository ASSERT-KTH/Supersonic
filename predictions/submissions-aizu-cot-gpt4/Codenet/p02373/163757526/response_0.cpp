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
void dfs(int u, int depth = 0) {
  idx_in_path[u] = path_size;
  path[path_size++] = ii(depth, u);
  for (int v : adjList[u]) {
    dfs(v, depth + 1);
    path[path_size++] = ii(depth, u);
  }
}
ii ST[MAXN << 1]; // Changed to 1D array
int Log[MAXN << 1]; // Added for pre-computation
void build(int n) {
  Log[1] = 0;
  for (int i = 2; i <= n; i++)
    Log[i] = Log[i/2] + 1; // Pre-compute the logarithms
  for (int i = 0; i < n; i++)
    ST[i] = path[i];
  for (int j = 1; j <= Log[n]; j++)
    for (int i = 0; i + (1 << j) <= n; i++)
      ST[i] = min(ST[i], ST[i + (1 << (j - 1))]); // Use pre-computed logarithms
}
int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;
  int p = Log[r - l]; // Use pre-computed logarithms
  return min(ST[l], ST[r - (1 << p)]).se;
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