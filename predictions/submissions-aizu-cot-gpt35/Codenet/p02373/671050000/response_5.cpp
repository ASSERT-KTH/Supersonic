#include <iostream>
#include <vector>
#include <stack>

struct HeavyLight {
  std::vector<std::vector<int>> tree;
  int n;
  std::vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;

  HeavyLight(const std::vector<std::vector<int>>& tree)
      : tree(tree), n(tree.size()), size(n), parent(n), in(n), out(n), path(n),
        pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    dfs(0, -1, time);
    buildPaths();
  }

  void dfs(int u, int p, int& k) {
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
    pathRoot.push_back(u);
    return pathRoot.size() - 1;
  }

  void buildPaths() {
    std::stack<std::pair<int, int>> stk;
    stk.push({0, newPath(0)});
    while (!stk.empty()) {
      int u = stk.top().first;
      int pt = stk.top().second;
      stk.pop();
      path[u] = pt;
      pathPos[u] = pathSize[pt]++;
      int maxSubtreeSize = 0;
      for (int v : tree[u]) {
        if (v != parent[u]) {
          if (2 * size[v] >= size[u]) {
            stk.push({v, pt});
          } else {
            stk.push({v, newPath(v)});
          }
          maxSubtreeSize = std::max(maxSubtreeSize, size[v]);
        }
      }
      size[u] = 1 + maxSubtreeSize;
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
  std::ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> tree(n);
  for (int i = 0; i < n; ++i) {
    int k;
    std::cin >> k;
    tree[i].resize(k);
    for (int j = 0; j < k; ++j) {
      std::cin >> tree[i][j];
    }
  }
  HeavyLight hl = HeavyLight(tree);
  int q;
  std::cin >> q;
  while (q--) {
    int u, v;
    std::cin >> u >> v;
    std::cout << hl.lca(u, v) << "\n";
  }
  return 0;
}