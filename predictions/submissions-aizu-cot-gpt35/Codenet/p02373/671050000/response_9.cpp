#include <iostream>
#include <vector>
using namespace std;

struct HeavyLight {
  vector<vector<int>> len, tree;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;

  HeavyLight(vector<vector<int>>&& tree)
      : tree(move(tree)), size(tree.size()), parent(tree.size()),
        in(tree.size()), out(tree.size()), path(tree.size()),
        pathSize(tree.size()), pathPos(tree.size()), pathRoot(tree.size()) {
    dfs(0, -1);
    buildPaths(0, newPath(0));
    len.resize(pathRoot.size());
    for (int i = 0; i < len.size(); ++i) {
      int m = pathSize[i];
      len[i].resize(2 * m);
      for (int j = 2 * m - 1; j > 1; j -= 2)
        len[i][j >> 1] = len[i][j] + len[i][j ^ 1];
    }
  }

  void dfs(int u, int p) {
    static int k = 0;
    in[u] = k++;
    parent[u] = p;
    size[u] = 1;
    for (int v : tree[u]) {
      if (v != p) {
        dfs(v, u);
        size[u] += size[v];
      }
    }
    out[u] = k++;
  }

  int newPath(int u) {
    pathRoot.push_back(u);
    return pathRoot.size() - 1;
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
    int root_a = pathRoot[path[a]];
    int root_b = pathRoot[path[b]];
    while (!isAncestor(root_a, b)) {
      a = parent[root_a];
      root_a = pathRoot[path[a]];
    }
    while (!isAncestor(root_b, a)) {
      b = parent[root_b];
      root_b = pathRoot[path[b]];
    }
    return isAncestor(a, b) ? a : b;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  tree.reserve(n);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    tree.emplace_back(k);
    for (int j = 0; j < k; ++j) {
      int ch;
      cin >> ch;
      tree[i].push_back(ch);
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