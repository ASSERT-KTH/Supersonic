#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct HeavyLight {
  vector<vector<int>> len, tree;
  int pathCount, n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;
  
  HeavyLight(vector<vector<int>> tree)
      : tree(tree), n(tree.size()) {
    int time = 0;
    size.resize(n);
    parent.resize(n);
    in.resize(n);
    out.resize(n);
    path.resize(n);
    pathSize.resize(n);
    pathPos.resize(n);
    pathRoot.resize(n);
    
    dfs(0, -1, time);
    buildPaths(0, newPath(0));

    len.resize(pathCount);
    for (int i = 0; i < pathCount; i++) {
      int m = pathSize[i];
      len[i].resize(2 * m, 1);
      for (int j = 2 * m - 1; j > 1; j -= 2)
        len[i][j >> 1] = len[i][j] + len[i][j ^ 1];
    }
  }
  
  void dfs(int u, int p, int &k) {
    in[u] = k++;
    parent[u] = p;
    size[u] = 1;
    for (int v : tree[u]) {
      if (v != p) {
        dfs(v, u, k);
        size[u] += size[v];
      }
    }
    out[u] = k++;
  }
  
  int newPath(int u) {
    pathRoot[pathCount] = u;
    return pathCount++;
  }
  
  void buildPaths(int u, int pt) {
    path[u] = pt;
    pathPos[u] = pathSize[pt]++;
    for (int v : tree[u]) {
      if (v != parent[u]) {
        buildPaths(v, 2 * size[v] >= size[u] ? pt : newPath(v));
      }
    }
  }

  bool isAncestor(int p, int ch) {
    return in[p] <= in[ch] && out[ch] <= out[p];
  }

  int lca(int a, int b) {
    while (!isAncestor(pathRoot[path[a]], b)) {
      a = parent[pathRoot[path[a]]];
    }
    while (!isAncestor(pathRoot[path[b]], a)) {
      b = parent[pathRoot[path[b]]];
    }
    return isAncestor(a, b) ? a : b;
  }
};

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  vector<vector<int>> tree(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    tree[i].resize(k);
    for (int j = 0; j < k; j++) {
      cin >> tree[i][j];
    }
  }
  
  HeavyLight hl = HeavyLight(tree);
  
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << hl.lca(u, v) << '\n';
  }
  
  return 0;
}