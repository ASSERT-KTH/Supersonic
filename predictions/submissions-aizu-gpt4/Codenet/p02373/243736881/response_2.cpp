#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int B = 200;
const int MAX = 100010;
int color[MAX], par[MAX], depth[MAX], top[MAX], goUp[MAX];
bool vis[MAX];
int n;
vector<vector<int>> g(MAX);
void decomp(int root) {
  fill(vis, vis+n, false);
  fill(par, par+n, -1);
  queue<int> q;
  q.push(root);
  vector<int> tord;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    vis[v] = true;
    tord.push_back(v);
    for (auto c : g[v]) {
      if (!vis[c]) {
        q.push(c);
        par[c] = v;
        depth[c] = depth[v] + 1;
      }
    }
  }
  fill(vis, vis+n, false);
  int c = 0;
  for (auto u : tord) {
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
      for (auto c : g[v]) {
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
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i=0; i<n; i++) {
    int k;
    cin >> k;
    while(k--) {
      int c;
      cin >> c;
      g[i].push_back(c);
      par[c] = i;
    }
  }
  decomp(0);
  int q;
  cin >> q;
  while(q--) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v) << "\n";
  }
  return 0;
}