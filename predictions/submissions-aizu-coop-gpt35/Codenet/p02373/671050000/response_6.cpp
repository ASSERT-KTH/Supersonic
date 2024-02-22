#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct HeavyLight {
  vector<int> edges;
  int pathCount, n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;
  
  HeavyLight(vector<vector<int>> tree)
      : n(tree.size()), size(n), parent(n), in(n), out(n), path(n),
        pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    dfs(0, -1, time, tree);
    buildPaths(tree);
  }
  
  void dfs(int u, int p, int &k, const vector<vector<int>>& tree) {
    in[u] = k++;
    parent[u] = p;
    size[u] = 1;
    for (int v : tree[u]) {
      if (v != p) {
        dfs(v, u, k, tree);
        size[u] += size[v];
      }
    }
    out[u] = k++;
  }
  
  int newPath(int u) {
    pathRoot[pathCount] = u;
    return pathCount++;
  }
  
  void buildPaths(const vector<vector<int>>& tree) {
    vector<int> stack;
    stack.push_back(0);
    while (!stack.empty()) {
      int u = stack.back();
      stack.pop_back();
      path[u] = newPath(u);
      pathPos[u] = pathSize[path[u]]++;
      for (int v : tree[u]) {
        if (v != parent[u]) {
          if (2 * size[v] >= size[u]) {
            path[v] = path[u];
            pathPos[v] = pathSize[path[u]]++;
          } else {
            stack.push_back(v);
          }
        }
      }
    }
  }
  
  bool isAncestor(int p, int ch) {
    return in[p] <= in[ch] && out[ch] <= out[p];
  }
  
  int lca(int a, int b) {
    while (!isAncestor(pathRoot[path[a]], b))
      a = parent[pathRoot[path[a]]];
    while (!isAncestor(pathRoot[path[b]], a))
      b = parent[pathRoot[path[b]]];
    return isAncestor(a, b) ? a : b;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    tree[i].resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> tree[i][j];
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