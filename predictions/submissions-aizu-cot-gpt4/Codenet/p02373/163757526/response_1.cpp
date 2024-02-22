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
stack<pair<int, int>> dfsStack;
void dfs(int u, int depth = 0) {
  dfsStack.push({u, depth});
  while (!dfsStack.empty()) {
    tie(u, depth) = dfsStack.top();
    dfsStack.pop();
    idx_in_path[u] = path_size;
    path[path_size++] = ii(depth, u);
    for (int v : adjList[u]) {
      dfsStack.push({v, depth + 1});
      path[path_size++] = ii(depth, u);
    }
  }
}
ii ST[LOGN][MAXN << 1];
void build(int n) {
  int h = ceil(log2(n + 1));
  for (int i = 0; i < n; i++)
    ST[0][i] = path[i];
  for (int i = 1; i < h; i++) {
    int shift_i = 1 << i;
    int shift_i_minus_1 = 1 << (i - 1);
    for (int j = 0; j + shift_i <= n; j++)
      ST[i][j] = min(ST[i - 1][j], ST[i - 1][j + shift_i_minus_1]);
  }
}
int lca(int u, int v) {
  int l = idx_in_path[u], r = idx_in_path[v];
  if (l > r)
    swap(l, r);
  r++;
  int p = 31 - __builtin_clz(r - l);
  return min(ST[p][l], ST[p][r - (1 << p)]).se;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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