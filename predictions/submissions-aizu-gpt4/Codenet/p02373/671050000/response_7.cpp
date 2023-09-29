#include <iostream>
#include <vector>
using namespace std;

struct HeavyLight {
  vector<vector<int>> tree;
  vector<int> size, parent, in, out, path;
  int n, time = 0;

  HeavyLight(vector<vector<int>>& tree) : tree(tree), n(tree.size()), size(n), 
  parent(n), in(n), out(n), path(n) {
    dfs(0, -1);
  }

  void dfs(int u, int p) {
    in[u] = time++;
    parent[u] = p;
    size[u] = 1;
    for(auto v : tree[u]) 
      if(v != p) 
        dfs(v, u), size[u] += size[v];
    out[u] = time++;
  }

  bool isAncestor(int p, int ch) {
    return in[p] <= in[ch] && out[ch] <= out[p];
  }

  int lca(int a, int b) {
    while(!isAncestor(path[a], b)) 
      a = parent[path[a]];
    while(!isAncestor(path[b], a)) 
      b = parent[path[b]];
    return in[a] < in[b] ? a : b;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> tree(n);
  for(int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    while(k--) {
      int ch;
      cin >> ch;
      tree[i].push_back(ch);
    }
  }
  HeavyLight hl(tree);
  int q;
  cin >> q;
  while(q--) {
    int u, v;
    cin >> u >> v;
    cout << hl.lca(u, v) << "\n";
  }
  return 0;
}