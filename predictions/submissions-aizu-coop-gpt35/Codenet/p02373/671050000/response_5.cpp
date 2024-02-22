#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct HeavyLight {
  vector<pair<int, int>> treeEdges;
  int pathCount, n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;
  vector<vector<int>> len;

  HeavyLight(vector<pair<int, int>> treeEdges)
      : treeEdges(treeEdges), n(treeEdges.size()), size(n), parent(n), in(n), out(n), path(n),
        pathSize(n), pathPos(n), pathRoot(n) {
    int time = 0;
    stack<pair<int, int>> st;
    st.push({0, -1});
    while (!st.empty()) {
      int u = st.top().first;
      int p = st.top().second;
      st.pop();
      in[u] = time++;
      parent[u] = p;
      size[u] = 1;
      for (int i = 0; i < treeEdges.size(); ++i) {
        int v = treeEdges[i].second;
        if (treeEdges[i].first == u && v != p) {
          st.push({v, u});
          size[u] += size[v];
        }
      }
      out[u] = time++;
    }

    buildPaths(0, newPath(0));

    len = vector<vector<int>>(pathCount);
    for (int i = 0; i < pathCount; ++i) {
      int m = pathSize[i];
      len[i].resize(2 * m);
      fill(len[i].begin(), len[i].end(), 0);
      fill(len[i].begin() + m, len[i].end(), 1);
      for (int j = 2 * m - 1; j > 1; j -= 2)
        len[i][j >> 1] = len[i][j] + len[i][j ^ 1];
    }
  }

  int newPath(int u) {
    pathRoot[pathCount] = u;
    return pathCount++;
  }

  void buildPaths(int u, int pt) {
    path[u] = pt;
    pathPos[u] = pathSize[pt]++;
    int heavyChild = -1;
    for (int i = 0; i < treeEdges.size(); ++i) {
      int v = treeEdges[i].second;
      if (treeEdges[i].first == u && v != parent[u]) {
        if (heavyChild == -1 || size[v] > size[heavyChild]) {
          heavyChild = v;
        }
      }
    }
    if (heavyChild != -1) {
      buildPaths(heavyChild, pt);
    }
    for (int i = 0; i < treeEdges.size(); ++i) {
      int v = treeEdges[i].second;
      if (treeEdges[i].first == u && v != parent[u] && v != heavyChild) {
        buildPaths(v, newPath(v));
      }
    }
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

  bool isAncestor(int p, int ch) {
    return in[p] <= in[ch] && out[ch] <= out[p];
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> treeEdges(n);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int ch;
      cin >> ch;
      treeEdges.push_back({i, ch});
    }
  }
  HeavyLight hl = HeavyLight(treeEdges);
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << hl.lca(u, v) << "\n";
  }
  return 0;
}