#include <iostream>
#include <queue>
#include <vector>

const int MAX_NODES = 100010;

int color[MAX_NODES], par[MAX_NODES], depth[MAX_NODES];
int top[MAX_NODES];
int goUp[MAX_NODES];
int n;
std::vector<int> g[MAX_NODES];

void decomp(int root) {
  std::vector<bool> vis(n, false);
  std::queue<int> q;
  q.push(root);
  std::vector<int> tord;
  while (!q.empty()) {
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
  std::fill(vis.begin(), vis.end(), false);
  int c = 0;
  for (int u : tord) {
    if (vis[u])
      continue;
    q.push(u);
    while (!q.empty() && q.size() < MAX_NODES) {
      int v = q.front();
      q.pop();
      vis[v] = true;
      color[v] = c;
      goUp[v] = par[u];
      top[v] = u;
      for (int c : g[v]) {
        if (!vis[c])
          q.push(c);
      }
    }
    while (!q.empty())
      q.pop();
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