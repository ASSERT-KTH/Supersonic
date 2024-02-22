#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

const int B = 200;

int n;
std::vector<std::vector<int>> g;
std::vector<int> depth, top, goUp;
std::unordered_map<int, int> par, color;

void decomp(int root) {
  std::vector<bool> vis(n, false);
  std::queue<int> q;
  q.push(root);
  std::vector<int> tord;
  int level = 0;
  while (!q.empty()) {
    int size = q.size();
    if (level >= B) break;
    for (int i = 0; i < size; i++) {
      int v = q.front();
      q.pop();
      vis[v] = true;
      tord.push_back(v);
      for (int c : g[v]) {
        if (!vis[c]) {
          q.push(c);
          par[c] = v;
          depth[c] = depth[v] + 1;
        }
      }
    }
    level++;
  }
  int c = 0;
  for (int u : tord) {
    if (vis[u]) continue;
    q.push(u);
    int k = 0;
    while (!q.empty() && k < B) {
      int v = q.front();
      q.pop();
      vis[v] = true;
      color[v] = c;
      goUp[v] = par[u];
      top[v] = u;
      k++;
      for (int c : g[v]) {
        if (!vis[c]) q.push(c);
      }
    }
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
  g.reserve(n);
  depth.resize(n);
  top.resize(n);
  goUp.resize(n);
  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    std::vector<int> adj(k);
    for (int j = 0; j < k; j++) {
      std::cin >> adj[j];
      par[adj[j]] = i;
    }
    g.push_back(adj);
  }
  decomp(0);
  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    std::cin >> u >> v;
    std::cout << solve(u, v) << std::endl;
  }
  return 0;
}