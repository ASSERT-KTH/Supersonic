#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define EACH(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define ALL(A) A.begin(), A.end()
using namespace std;
struct HeavyLight {
  vector<vector<int>> len, tree;
  int pathCount, n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;
  HeavyLight(vector<vector<int>> tree)
      : tree(tree), n(tree.size()), size(n), parent(n), in(n), out(n), path(n),
        pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    dfs(0, -1, time);
    buildPaths(0, newPath(0));
    len.reserve(pathCount);
    REP(i, pathCount) {
      int m = pathSize[i];
      vector<int> tempLen(2 * m);
      fill(tempLen.begin() + m, tempLen.end(), 1);
      for (int j = 2 * m - 1; j > 1; j -= 2)
        tempLen[j >> 1] = tempLen[j] + tempLen[j ^ 1];
      len.push_back(tempLen);
    }
  }
  void dfs(int u, int p, int &k) {
    in[u] = k++, parent[u] = p, size[u] = 1;
    EACH(v, tree[u]) if (*v != p) dfs(*v, u, k), size[u] += size[*v];
    out[u] = k++;
  }
  int newPath(int u) {
    pathRoot[pathCount] = u;
    return pathCount++;
  }
  void buildPaths(int u, int pt) {
    path[u] = pt, pathPos[u] = pathSize[pt]++;
    EACH(v, tree[u])
    if (*v != parent[u])
        buildPaths(*v, 2 * size[*v] >= size[u] ? pt : newPath(*v));
  }
  bool isAncestor(int p, int ch) {
    return in[p] <= in[ch] && out[ch] <= out[p];
  }
  int lca(int a, int b) {
    for (int root; !isAncestor(root = pathRoot[path[a]], b); a = parent[root])
      ;
    for (int root; !isAncestor(root = pathRoot[path[b]], a); b = parent[root])
      ;
    return isAncestor(a, b) ? a : b;
  }
};
int main(void) {
  ios::sync_with_stdio(false);
  int n;
  scanf("%d", &n);
  vector<vector<int>> tree(n);
  REP(i, n) {
    int k;
    scanf("%d", &k);
    tree[i].reserve(k);
    REP(j, k) {
      int ch;
      scanf("%d", &ch);
      tree[i].push_back(ch);
    }
  }
  HeavyLight hl = HeavyLight(tree);
  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", hl.lca(u, v));
  }
  return 0;
}