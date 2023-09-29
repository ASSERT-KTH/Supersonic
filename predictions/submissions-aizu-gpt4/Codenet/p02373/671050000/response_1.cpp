#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(A) A.begin(), A.end()
using namespace std;

struct HeavyLight {
  vector<vector<int>> len, tree;
  int pathCount, n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;

  HeavyLight(vector<vector<int>> tree)
      : tree(move(tree)), n(this->tree.size()), size(n), parent(n), in(n), 
        out(n), path(n), pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    dfs(0, -1, time);
    buildPaths(0, newPath(0));
    len.resize(pathCount);
    REP(i, pathCount) {
      int m = pathSize[i];
      len[i].resize(2 * m, 0);
      fill(len[i].begin() + m, len[i].begin() + 2 * m, 1);
      for (int j = 2 * m - 1; j > 1; j -= 2)
        len[i][j >> 1] = len[i][j] + len[i][j ^ 1];
    }
  }

  void dfs(int u, int p, int &k) {
    in[u] = k++, parent[u] = p, size[u] = 1;
    for (int v : tree[u]) 
      if (v != p) dfs(v, u, k), size[u] += size[v];
    out[u] = k++;
  }

  int newPath(int u) {
    pathRoot[pathCount] = u;
    return pathCount++;
  }

  void buildPaths(int u, int pt) {
    path[u] = pt, pathPos[u] = pathSize[pt]++;
    for (int v : tree[u]) 
      if (v != parent[u])
        buildPaths(v, 2 * size[v] >= size[u] ? pt : newPath(v));
  }

  bool isAncestor(int p, int ch) const {
    return in[p] <= in[ch] && out[ch] <= out[p];
  }

  int lca(int a, int b) const {
    while (!isAncestor(pathRoot[path[a]], b)) 
      a = parent[pathRoot[path[a]]];
    while (!isAncestor(pathRoot[path[b]], a)) 
      b = parent[pathRoot[path[b]]];
    return in[a] < in[b] ? a : b;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  REP(i, n) {
    int k;
    cin >> k;
    tree[i].resize(k);
    REP(j, k) {
      cin >> tree[i][j];
    }
  }
  HeavyLight hl = HeavyLight(move(tree));
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << hl.lca(u, v) << "\n";
  }
  return 0;
}