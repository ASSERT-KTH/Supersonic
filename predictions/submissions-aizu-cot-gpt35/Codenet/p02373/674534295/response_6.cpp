#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define all(c) begin(c), end(c)
const int INF =
    sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
using Weight = int;
struct LowestCommonAncestor {
  const int n, log2_n;
  vector<vector<int>> parent;
  vector<int> depth;
  LowestCommonAncestor(const vector<int>& parent, const vector<int>& depth)
      : n(parent.size()), log2_n(log2(n) + 1), parent(log2_n, vector<int>(n)),
        depth(depth) {
    for (int v = 0; v < n; v++) {
      parent[0][v] = parent[v];
    }
    for (int k = 0; k + 1 < log2_n; k++) {
      for (int v = 0; v < n; v++) {
        if (parent[k][v] < 0)
          parent[k + 1][v] = -1;
        else
          parent[k + 1][v] = parent[k][parent[k][v]];
      }
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
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> parent(n);
  vector<int> depth(n);
  rep(i, 1, n) {
    int p;
    cin >> p;
    parent[i] = p;
    depth[i] = depth[p] + 1;
  }
  int q;
  cin >> q;
  LowestCommonAncestor lca(parent, depth);
  rep(i, 0, q) {
    int u, v;
    cin >> u >> v;
    cout << lca.get(u, v) << endl;
  }
  return 0;
}