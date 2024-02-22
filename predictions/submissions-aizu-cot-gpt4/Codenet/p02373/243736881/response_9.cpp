#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int B = 200;
int color[100010], par[100010], depth[100010];
int top[100010];
int goUp[100010];
bool vis[100010];
int n;
std::vector<std::vector<int>> g;

void decomp(int root) {
  rep(i, n) vis[i] = false, par[i] = -1;
  std::queue<int> q;
  q.push(root);
  std::vector<int> tord;
  tord.reserve(n);
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
  rep(i, n) vis[i] = false;
  int c = 0;
  for (int u : tord) {
    if (vis[u])
      continue;
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
        if (!vis[c])
          q.push(c);
      }
    }
    while (!q.empty())
      q.pop();
    c++;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  std::cin >> n;
  g.assign(n, {});
  rep(i, n) {
    int k;
    std::cin >> k;
    g[i].reserve(k);
    rep(j, k) {
      int c;
      std::cin >> c;
      g[i].push_back(c);
      par[c] = i;
    }
  }
  decomp(0);
  int q;
  std::cin >> q;
  rep(i, q) {
    int u, v;
    std::cin >> u >> v;
    std::cout << solve(u, v) << '\n';
  }
}