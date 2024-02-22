#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define MAXN 100005
#define LOG2N 20
using namespace std;
struct Edge { int s, d; };
using Graph = vector<vector<Edge>>;
int parent[LOG2N][MAXN], depth[MAXN];
void dfs(const Graph &g, int s, int p, int d) {
  parent[0][s] = p;
  depth[s] = d;
  for (auto &e : g[s]) {
    if (e.d == p) continue;
    dfs(g, e.d, s, d + 1);
  }
}
int lca(int u, int v, int log2_n) {
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < log2_n; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
    }
  }
  if (u == v) return u;
  for (int k = log2_n - 1; k >= 0; k--) {
    if (parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}
int main() {
  int n;
  scanf("%d", &n);
  Graph g(n);
  rep(i, 0, n) {
    int k;
    scanf("%d", &k);
    rep(j, 0, k) {
      int c;
      scanf("%d", &c);
      g[i].push_back({i, c});
    }
  }
  int log2_n = log2(n) + 1;
  dfs(g, 0, -1, 0);
  for (int k = 0; k + 1 < log2_n; k++) {
    rep(v, 0, n) {
      if (parent[k][v] < 0) parent[k + 1][v] = -1;
      else parent[k + 1][v] = parent[k][parent[k][v]];
    }
  }
  int q;
  scanf("%d", &q);
  rep(i, 0, q) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", lca(u, v, log2_n));
  }
  return 0;
}