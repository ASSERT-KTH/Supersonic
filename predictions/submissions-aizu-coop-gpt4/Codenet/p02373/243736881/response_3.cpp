#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int B = 200;
int color[100010], par[100010], depth[100010];
int top[100010];
int goUp[100010];
bool vis[100010];
int n;
vector<vector<int>> g;

void decomp(int root) {
  rep(i, n) vis[i] = false, par[i] = -1;
  queue<int> q;
  q.push(root);
  vector<int> tord; tord.reserve(n);
  while (!q.empty()) {
    int v = q.front(); q.pop();
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
  int c = 0;
  for (int u : tord) {
    if (vis[u]) continue;
    stack<int> s; s.push(u);
    int k = 0;
    while (!s.empty() && k < B) {
      int v = s.top(); s.pop();
      vis[v] = true;
      color[v] = c;
      goUp[v] = par[u];
      top[v] = u;
      k++;
      for (int c : g[v]) {
        if (!vis[c]) s.push(c);
      }
    }
    c++;
  }
}

int solve(int u, int v) {
  while (color[u] != color[v]) {
    assert(u != -1 && v != -1);
    if (depth[top[u]] > depth[top[v]]) u = goUp[u];
    else v = goUp[v];
  }
  while (u != v) {
    assert(u != -1 && v != -1);
    if (depth[u] > depth[v]) u = par[u];
    else v = par[v];
  }
  return u;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); // disable synchronization
  cin >> n;
  g.assign(n, {});
  rep(i, n) {
    int k; cin >> k;
    while (k--) {
      int c; cin >> c;
      g[i].push_back(c);
      par[c] = i;
    }
  }
  decomp(0);
  int q; cin >> q;
  while (q--) {
    int u, v; cin >> u >> v;
    cout << solve(u, v) << '\n';
  }
  return 0;
}