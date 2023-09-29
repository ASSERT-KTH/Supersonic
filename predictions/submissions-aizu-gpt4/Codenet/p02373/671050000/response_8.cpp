#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class HeavyLight {
  vector<vector<int>> len, tree;
  int pathCount, n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;

public:
  explicit HeavyLight(vector<vector<int>> tree)
      : tree(move(tree)), n(this->tree.size()), size(n), parent(n), in(n),
        out(n), path(n), pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    dfs(0, -1, time);
    buildPaths(0, newPath(0));
    len.resize(pathCount);
    for (int i = 0; i < pathCount; ++i) {
      int m = pathSize[i];
      len[i].resize(2 * m);
      fill(len[i].begin() + m, len[i].begin() + 2 * m, 1);
      for (int j = 2 * m - 1; j > 1; j -= 2)
        len[i][j >> 1] = len[i][j] + len[i][j ^ 1];
    }
  }

  int lca(int a, int b) {
    while (!isAncestor(pathRoot[path[a]], b))
      a = parent[pathRoot[path[a]]];
    while (!isAncestor(pathRoot[path[b]], a))
      b = parent[pathRoot[path[b]]];
    return in[a] < in[b] ? a : b;
  }

private:
  void dfs(int u, int p, int &k) {
    in[u] = k++;
    parent[u] = p;
    size[u] = 1;
    for (auto v : tree[u])
      if (v != p) {
        dfs(v, u, k);
        size[u] += size[v];
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
    for (auto v : tree[u])
      if (v != parent[u])
        buildPaths(v, 2 * size[v] >= size[u] ? pt : newPath(v));
  }

  bool isAncestor(int p, int ch) const {
    return in[p] <= in[ch] && out[ch] <= out[p];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  for (auto &edges : tree) {
    int k;
    cin >> k;
    edges.resize(k);
    for (int &ch : edges)
      cin >> ch;
  }

  HeavyLight hl(move(tree));

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << hl.lca(u, v) << "\n";
  }
}