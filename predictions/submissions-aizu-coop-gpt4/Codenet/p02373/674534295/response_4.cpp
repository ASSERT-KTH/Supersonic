#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;

const int INF = 1e9+7;
vector<vector<int>> parent;
vector<int> depth;

void dfs(const vector<vector<int>> &g, int s, int p, int d) {
    parent[0][s] = p;
    depth[s] = d;
    for (auto &e : g[s]) {
      if (e == p)
        continue;
      dfs(g, e, s, d + 1);
    }
}

int get(int u, int v) {
    int log2_n = parent.size();
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

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> g(n);
  for (int i=0; i<n; i++) {
    int k;
    scanf("%d", &k);
    for (int j=0; j<k; j++) {
      int c;
      scanf("%d", &c);
      g[i].push_back(c);
    }
  }
  int q;
  scanf("%d", &q);
  int log2_n = log2(n) + 1;
  parent.assign(log2_n, vector<int>(n));
  depth.assign(n, 0);
  dfs(g, 0, -1, 0);
  for (int i = 0; i < q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", get(u, v));
  }
  return 0;
}