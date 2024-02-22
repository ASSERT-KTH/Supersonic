#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, a, b) for (int i = int(a); i < int(b); ++i)
#define EACH(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(A) A.begin(), A.end()
using namespace std;
struct HeavyLight {
  vector<vector<int>> tree;
  int pathCount, n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;
  HeavyLight(vector<vector<int>> tree)
      : tree(tree), n(tree.size()), size(n), parent(n), in(n), out(n), path(n),
        pathSize(n), pathPos(n), pathRoot(n) {
    dfs(0, -1);
    buildPaths(0, 0);
  }
  void dfs(int u, int p) {
    in[u] = parent[u] = p;
    size[u] = 1;
    EACH(v, tree[u])
    if (*v != p) {
        dfs(*v, u);
        size[u] += size[*v];
    }
    out[u] = p;
  }
  void buildPaths(int u, int pt) {
    path[u] = pt;
    pathPos[u] = pathSize[pt]++;
    EACH(v, tree[u])
    if (*v != parent[u])
        buildPaths(*v, 2 * size[*v] >= size[u] ? pt : ++pathCount);
  }
  int lca(int a, int b) {
    while (!(in[pathRoot[path[a]]] <= in[b] && out[b] <= out[pathRoot[path[a]]]))
        a = parent[pathRoot[path[a]]];
    while (!(in[pathRoot[path[b]]] <= in[a] && out[a] <= out[pathRoot[path[b]]]))
        b = parent[pathRoot[path[b]]];
    return (in[a] <= in[b] && out[b] <= out[a]) ? a : b;
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