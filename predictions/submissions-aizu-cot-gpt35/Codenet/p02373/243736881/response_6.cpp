#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <deque>

const int B = 200;
const int MAX_N = 100010;

int color[MAX_N], par[MAX_N], depth[MAX_N];
int top[MAX_N];
int goUp[MAX_N];
bool vis[MAX_N];
int n;
std::array<std::deque<int>, MAX_N> g;

void decomp(int root) {
  for (int i = 0; i < n; i++) vis[i] = false;
  std::deque<int> q;
  q.push_back(root);
  std::vector<int> tord;
  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
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
  for (int i = 0; i < n; i++) vis[i] = false;
  int c = 0;
  for (int u : tord) {
    if (vis[u])
      continue;
    q.push_back(u);
    int k = 0;
    while (!q.empty() && k < B) {
      int v = q.front();
      q.pop_front();
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