#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct HeavyLight {
  vector<vector<int>> len, tree;
  int pathCount, n;
  vector<int> size, parent, in, out, path, pathSize, pathPos, pathRoot;
  vector<vector<int>> ancestor_cache;
  HeavyLight(vector<vector<int>> tree)
      : tree(tree), n(tree.size()), size(n), parent(n), in(n), out(n), path(n),
        pathSize(n), pathPos(n), pathRoot(n), ancestor_cache(n, vector<int>(n, -1)) {
    int time = 0;
    dfs(0);
    buildPaths();
    len = vector<vector<int>>(pathCount);
    for(int i = 0; i < pathCount; i++) {
      int m = pathSize[i];
      len[i].resize(m);
      fill(len[i].begin(), len[i].begin() + m, 1);
      for (int j = m - 1; j > 1; j -= 2)
        len[i][j >> 1] = len[i][j] + len[i][j ^ 1];
    }
  }
  void dfs(int root) {
    stack<int> s;
    s.push(root);
    in[root] = 0;
    parent[root] = -1;
    size[root] = 1;
    int time = 1;
    while (!s.empty()){
      int u = s.top(); s.pop();
      for(auto v: tree[u]){
        if(parent[u] != v){
          s.push(v);
          in[v] = time++;
          parent[v] = u;
          size[v] = 1;
        }
      }
      out[u] = time++;
    }
  }
  int newPath(int u) {
    pathRoot[pathCount] = u;
    return pathCount++;
  }
  void buildPaths() {
    stack<int> s;
    s.push(0);
    newPath(0);
    while (!s.empty()){
      int u = s.top(); s.pop();
      for(auto v: tree[u]){
        if(parent[u] != v){
          s.push(v);
          path[v] = 2 * size[v] >= size[u] ? path[u] : newPath(v);
          pathPos[v] = pathSize[path[v]]++;
        }
      }
    }
  }
  bool isAncestor(int p, int ch) {
    if(ancestor_cache[p][ch] == -1)
      ancestor_cache[p][ch] = in[p] <= in[ch] && out[ch] <= out[p];
    return ancestor_cache[p][ch];
  }
  int lca(int a, int b) {
    while(!isAncestor(pathRoot[path[a]], b)) 
      a = parent[pathRoot[path[a]]];
    while(!isAncestor(pathRoot[path[b]], a)) 
      b = parent[pathRoot[path[b]]];
    return isAncestor(a, b) ? a : b;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  for(int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++) {
      int ch;
      cin >> ch;
      tree[i].push_back(ch);
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