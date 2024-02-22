#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 100000;
const int MAX_LOG_N = 17;

struct LowestCommonAncestor {
  const int n, log2_n;
  vector<int> parent[MAX_LOG_N];
  vector<int> depth;
  LowestCommonAncestor(const vector<vector<int>>& g, int root)
      : n(g.size()), log2_n(log2(n) + 1), depth(n) {
    dfs(g, root, -1, 0);
    for (int k = 0; k + 1 < log2_n; k++) {
      for (int v = 0; v < n; v++) {
        if (parent[k][v] < 0)
          parent[k + 1][v] = -1;
        else
          parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }
  void dfs(const vector<vector<int>>& g, int s, int p, int d) {
    parent[0][s] = p;
    depth[s] = d;
    for (int d : g[s]) {
      if (d == p)
        continue;
      dfs(g, d, s, d + 1);
    }
  }
  int get(int u, int v) {
    if (depth[u] > depth[v])
      swap(u, v);
    for (int k = 0; k < log2_n; k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v)
      return u;
    for (int k = log2_n - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    g[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> g[i][j];
    }
  }
  int u, v;
  cin >> u >> v;
  LowestCommonAncestor lca(g, 0);
  cout << lca.get(u, v) << endl;
  return 0;
}