#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, a, b) for (int i = int(a); i < int(b); ++i)
#define EACH(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(A) A.begin(), A.end()
using namespace std;
struct HeavyLight {
  vector<vector<int>> len, tree;
  int pathCount, n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;
  unordered_map<int, unordered_map<int, int>> lca_cache;
  HeavyLight(vector<vector<int>> tree)
      : tree(tree), n(tree.size()), size(n), parent(n), in(n), out(n), path(n),
        pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    dfs(0, -1, time);
    buildPaths(0, newPath(0));
    len = vector<vector<int>>(pathCount);
    REP(i, pathCount) {
      int m = pathSize[i];
      len[i].resize(2 * m);
      fill(len[i].begin() + m, len[i].begin() + 2 * m, 1);
      for (int j = 2 * m - 1; j > 1; j -= 2)
        len[i][j >> 1] = len[i][j] + len[i][j ^ 1];
    }
  }
  void dfs(int u, int p, int &k) {
    in[u] = k++, parent[u] = p, size[u] = 1;
    for(auto v : tree[u]) if (v != p) dfs(v, u, k), size[u] += size[v];
    out[u] = k++;
  }
  int newPath(int u) {
    pathRoot[pathCount] = u;
    return pathCount++;
  }
  void buildPaths(int u, int pt) {
    path[u] = pt, pathPos[u] = pathSize[pt]++;
    for(auto v : tree[u])
      if (v != parent[u])
        buildPaths(v, 2 * size[v] >= size[u] ? pt : newPath(v));
  }
  bool isAncestor(int p, int ch) {
    return in[p] <= in[ch] && out[ch] <= out[p];
  }
  int lca(int a, int b) {
    if (a > b) swap(a, b);
    if (lca_cache.count(a) && lca_cache[a].count(b))
        return lca_cache[a][b];
    int result;
    for (int root; !isAncestor(root = pathRoot[path[a]], b); a = parent[root])
      ;
    for (int root; !isAncestor(root = pathRoot[path[b]], a); b = parent[root])
      ;
    result = isAncestor(a, b) ? a : b;
    lca_cache[a][b] = result;
    return result;
  }
};
int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  REP(i, n) {
    int k;
    cin >> k;
    REP(j, k) {
      int ch;
      cin >> ch;
      tree[i].push_back(ch);
    }
  }
  HeavyLight hl = HeavyLight(tree);
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << hl.lca(u, v) << "\n";
  }
  return 0;
}