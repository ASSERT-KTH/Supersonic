#include <iostream>
#include <vector>

struct HeavyLight {
  std::vector<std::vector<int>> tree;
  int pathCount, n;
  std::vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;
  std::vector<std::vector<int>> len;

  HeavyLight(std::vector<std::vector<int>>&& tree)
      : tree(std::move(tree)), n(this->tree.size()), size(n), parent(n), in(n), out(n), path(n),
        pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    dfs(0, -1, time);
    buildPaths(0, newPath(0));
    len.resize(pathCount);
    for (int i = 0; i < pathCount; ++i) {
      int m = pathSize[i];
      len[i].resize(2 * m);
      std::fill(len[i].begin(), len[i].end(), 0);
      std::fill(len[i].begin() + m, len[i].begin() + 2 * m, 1);
      for (int j = 2 * m - 1; j > 1; j -= 2)
        len[i][j >> 1] = len[i][j] + len[i][j ^ 1];
    }
  }

  void dfs(int u, int p, int &k) {
    std::vector<int> stack;
    stack.push_back(u);
    parent[u] = p;
    in[u] = k++;
    size[u] = 1;
    while (!stack.empty()) {
      int v = stack.back();
      stack.pop_back();
      for (int i = 0; i < tree[v].size(); ++i) {
        int child = tree[v][i];
        if (child == p)
          continue;
        stack.push_back(child);
        parent[child] = v;
        in[child] = k++;
        size[child] = 1;
      }
    }
    out[u] = k++;
  }

  int newPath(int u) {
    pathRoot[pathCount] = u;
    return pathCount++;
  }

  void buildPaths(int u, int pt) {
    std::vector<int> stack;
    stack.push_back(u);
    path[u] = pt;
    pathPos[u] = pathSize[pt]++;
    while (!stack.empty()) {
      int v = stack.back();
      stack.pop_back();
      for (int i = 0; i < tree[v].size(); ++i) {
        int child = tree[v][i];
        if (child == parent[v])
          continue;
        stack.push_back(child);
        buildPaths(child, 2 * size[child] >= size[v] ? pt : newPath(child));
      }
    }
  }

  bool isAncestor(int p, int ch) {
    return in[p] <= in[ch] && out[ch] <= out[p];
  }

  int lca(int a, int b) {
    int root;
    while (!isAncestor(root = pathRoot[path[a]], b))
      a = parent[root];
    while (!isAncestor(root = pathRoot[path[b]], a))
      b = parent[root];
    return isAncestor(a, b) ? a : b;
  }
};

int main() {
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
  HeavyLight hl = HeavyLight(std::move(tree));
  int q;
  std::cin >> q;
  while (q--) {
    int u, v;
    std::cin >> u >> v;
    std::cout << hl.lca(u, v) << "\n";
  }
  return 0;
}