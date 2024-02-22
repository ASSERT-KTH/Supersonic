#include <iostream>
#include <vector>

using namespace std;

struct HeavyLight {
  vector<vector<int>> len, tree;
  int pathCount, n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;

  HeavyLight(vector<vector<int>>& tree)
      : tree(move(tree)), n(tree.size()), size(n), parent(n), in(n), out(n), path(n),
        pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    dfs(0, -1, time);
    buildPaths(0, newPath(0));
    len.reserve(pathCount);
    for (int i = 0; i < pathCount; ++i) {
      int m = pathSize[i];
      len.emplace_back(2 * m);
      fill(len[i].begin(), len[i].end(), 0);
      fill(len[i].begin() + m, len[i].end(), 1);
      for (int j = 2 * m - 1; j > 1; j -= 2)
        len[i][j >> 1] = len[i][j] + len[i][j ^ 1];
    }
  }

  void dfs(int u, int p, int& k) {
    in[u] = ++k;
    parent[u] = p;
    size[u] = 1;
    for (int v : tree[u]) {
      if (v != p) {
        dfs(v, u, k);
        size[u] += size[v];
      }
    }
    out[u] = ++k;
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
    int root;
    while (!isAncestor(root = pathRoot[path[a]], b)) {
      a = parent[root];
    }
    while (!isAncestor(root = pathRoot[path[b]], a)) {
      b = parent[root];
    }
    return isAncestor(a, b) ? a : b;
  }
};

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    tree[i].reserve(k);
    for (int j = 0; j < k; ++j) {
      int ch;
      cin >> ch;
      tree[i].emplace_back(ch);
    }
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