#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct HeavyLight {
  vector<vector<int>> len, tree;
  int pathCount, n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;

  HeavyLight(vector<vector<int>> tree)
      : tree(tree), n(tree.size()), size(n), parent(n), in(n), out(n),
        path(n), pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    dfs(0, -1, time);
    buildPaths();
    initLen();
  }

  void dfs(int root, int p, int &k) {
    stack<pair<int, int>> st;
    st.push({root, p});

    while (!st.empty()) {
      int u = st.top().first;
      int par = st.top().second;
      st.pop();

      in[u] = k++;
      parent[u] = par;
      size[u] = 1;

      for (int v : tree[u]) {
        if (v != par) {
          st.push({v, u});
        }
      }
    }
  }

  void buildPaths() {
    stack<pair<int, int>> st;
    st.push({0, newPath(0)});

    while (!st.empty()) {
      int u = st.top().first;
      int pt = st.top().second;
      st.pop();

      path[u] = pt;
      pathPos[u] = pathSize[pt]++;

      for (int v : tree[u]) {
        if (v != parent[u]) {
          if (2 * size[v] >= size[u]) {
            st.push({v, pt});
          } else {
            st.push({v, newPath(v)});
          }
        }
      }
    }
  }

  void initLen() {
    len = vector<vector<int>>(pathCount);

    for (int i = 0; i < pathCount; ++i) {
      int m = pathSize[i];
      len[i].resize(2 * m);
      fill(len[i].begin(), len[i].end(), 0);
      fill(len[i].begin() + m, len[i].begin() + 2 * m, 1);

      for (int j = 2 * m - 1; j > 1; j -= 2) {
        len[i][j >> 1] = len[i][j] + len[i][j ^ 1];
      }
    }
  }

  int newPath(int u) {
    pathRoot[pathCount] = u;
    return pathCount++;
  }

  inline bool isAncestor(int p, int ch) {
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