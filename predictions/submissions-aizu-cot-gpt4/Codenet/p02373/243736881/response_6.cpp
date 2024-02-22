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
  for(int i = 0; i < n; i++) vis[i] = false, par[i] = -1;
  queue<int> q;
  q.push(root);
  vector<int> tord;
  tord.reserve(n);
  while (q.size()) {
    int v = q.front();
    q.pop();
    vis[v] = true;
    tord.emplace_back(v);
    for (int c : g[v]) {
      if (!vis[c]) {
        q.push(c);
        par[c] = v;
        depth[c] = depth[v] + 1;
      }
    }
  }
  for(int i = 0; i < n; i++) vis[i] = false;
  int c = 0;
  for (int u : tord) {
    if (vis[u])
      continue;
    q.push(u);
    int k = 0;
    while (q.size() && k < B) {
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
    while (q.size())
      q.pop();
    c++;
  }
}
int solve(int u, int v) {
  if (color[u] != color[v]) {
    while (color[u] != color[v]) {
      assert(u != -1 && v != -1);
      if (depth[top[u]] > depth[top[v]])
        u = goUp[u];
      else
        v = goUp[v];
    }
  }
  if (u != v) {
    while (u != v) {
      assert(u != -1 && v != -1);
      if (depth[u] > depth[v])
        u = par[u];
      else
        v = par[v];
    }
  }
  return u;
}
int main() {
  cin >> n;
  g.assign(n, {});
  rep(i, n) {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++) {
      int c;
      cin >> c;
      g[i].emplace_back(c);
      par[c] = i;
    }
  }
  decomp(0);
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v) << endl;
  }
}