#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int B = 200;

int color[100010], par[100010], depth[100010];
int top[100010], goUp[100010], vis[100010];
int n;
vector<vector<int>> g;

void decomp(int root) {
  rep(i, n) vis[i] = 0, par[i] = -1;
  queue<int> q;
  q.push(root);
  vector<int> tord;
  while (q.size()) {
    int v = q.front();
    q.pop();
    vis[v] = 1;
    tord.push_back(v);
    for (int c : g[v]) {
      if (!vis[c]) {
        q.push(c);
        par[c] = v;
        depth[c] = depth[v] + 1;
      }
    }
  }
  rep(i, n) vis[i] = 0;
  int c = 0;
  for (int u : tord) {
    if (vis[u]) continue;
    q.push(u);
    int k = 0;
    while (q.size() && k < B) {
      int v = q.front();
      q.pop();
      vis[v] = 1;
      color[v] = c;
      goUp[v] = par[u];
      top[v] = u;
      k++;
      for (int c : g[v]) {
        if (!vis[c]) q.push(c);
      }
    }
    while (q.size()) q.pop();
    c++;
  }
}

int solve(int u, int v) {
  while (color[u] != color[v]) {
    assert(u != -1 && v != -1);
    if (depth[top[u]] > depth[top[v]])
      u = goUp[u];
    else
      v = goUp[v];
  }
  while (u != v) {
    assert(u != -1 && v != -1);
    if (depth[u] > depth[v])
      u = par[u];
    else
      v = par[v];
  }
  return u;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  g.resize(n);
  rep(i, n) {
    int k;
    cin >> k;
    rep(j, k) {
      int c;
      cin >> c;
      g[i].push_back(c);
      par[c] = i;
    }
  }
  decomp(0);
  int q;
  cin >> q;
  rep(i, q) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v) << '\n';
  }
}