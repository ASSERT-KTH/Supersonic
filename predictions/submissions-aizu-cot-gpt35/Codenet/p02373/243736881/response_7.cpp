#include <iostream>
#include <vector>

const int B = 200;

int n;
std::vector<std::vector<int>> g;
std::vector<int> color, par, depth, top, goUp;

void decomp(int root) {
  std::vector<bool> vis(n, false);
  par.assign(n, -1);
  depth.assign(n, 0);
  top.assign(n, 0);
  goUp.assign(n, 0);

  std::vector<int> tord;
  std::vector<int> q;
  q.push_back(root);
  
  while (!q.empty()) {
    int v = q.back();
    q.pop_back();
    
    vis[v] = true;
    tord.push_back(v);
    
    for (int c : g[v]) {
      if (!vis[c]) {
        q.push_back(c);
        par[c] = v;
        depth[c] = depth[v] + 1;
      }
    }
  }
  
  vis.assign(n, false);
  int c = 0;
  
  for (int u : tord) {
    if (vis[u])
      continue;
    
    q.push_back(u);
    int k = 0;
    
    while (!q.empty() && k < B) {
      int v = q.back();
      q.pop_back();
      
      vis[v] = true;
      color[v] = c;
      goUp[v] = par[u];
      top[v] = u;
      k++;
      
      for (int c : g[v]) {
        if (!vis[c])
          q.push_back(c);
      }
    }
    
    q.clear();
    c++;
  }
}

int solve(int u, int v) {
  while (color[u] != color[v]) {
    if (depth[top[u]] > depth[top[v]])
      u = goUp[u];
    else
      v = goUp[v];
  }
  
  while (u != v) {
    if (depth[u] > depth[v])
      u = par[u];
    else
      v = par[v];
  }
  
  return u;
}

int main() {
  std::cin >> n;
  g.assign(n, {});
  
  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    
    for (int j = 0; j < k; j++) {
      int c;
      std::cin >> c;
      g[i].push_back(c);
      par[c] = i;
    }
  }
  
  decomp(0);
  
  int q;
  std::cin >> q;
  
  for (int i = 0; i < q; i++) {
    int u, v;
    std::cin >> u >> v;
    std::cout << solve(u, v) << std::endl;
  }
}