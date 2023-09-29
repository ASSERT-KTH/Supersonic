#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, a, b) for (int i = int(a); i < int(b); ++i)
using namespace std;
struct HeavyLight {
  vector<vector<int>> tree;
  int n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;
  HeavyLight(vector<vector<int>>& tree)
      : tree(tree), n(tree.size()), size(n), parent(n), in(n), out(n), path(n),
        pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    dfs(0, -1, time);
    buildPaths(0, newPath(0));
  }
  void dfs(int u, int p, int &k) {
    in[u] = k++, parent[u] = p, size[u] = 1;
    for (auto v : tree[u]) 
      if (v != p) dfs(v, u, k), size[u] += size[v];
    out[u] = k++;
  }
  int newPath(int u) {
    pathRoot[path.size()] = u;
    return path.size()++;
  }
  void buildPaths(int u, int pt) {
    path[u] = pt, pathPos[u] = pathSize[pt]++;
    for (auto v : tree[u])
      if (v != parent[u]) buildPaths(v, 2 * size[v] >= size[u] ? pt : newPath(v));
  }
  bool isAncestor(int p, int ch) {
    return in[p] <= in[ch] && out[ch] <= out[p];
  }
  int lca(int a, int b) {
    while (!isAncestor(pathRoot[path[a]], b)) a = parent[pathRoot[path[a]]];
    while (!isAncestor(pathRoot[path[b]], a)) b = parent[pathRoot[path[b]]];
    return isAncestor(a, b) ? a : b;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  REP(i, n) {
    int k;
    cin >> k;
    tree[i].resize(k);
    REP(j, k) cin >> tree[i][j];
  }
  HeavyLight hl(tree);
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << hl.lca(u, v) << "\n";
  }
  return 0;
}