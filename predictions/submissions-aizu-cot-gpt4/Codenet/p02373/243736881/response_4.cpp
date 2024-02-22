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
int n;
vector<vector<int>> g;
void decomp(int root) {
  rep(i, n) color[i] = -1, par[i] = -1;
  vector<int> tord;
  tord.reserve(n);
  {
    queue<int> q;
    q.push(root);
    while (q.size()) {
      int v = q.front();
      q.pop();
      color[v] = 0;
      tord.push_back(v);
      for (int c : g[v]) {
        if (color[c] == -1) {
          q.push(c);
          par[c] = v;
          depth[c] = depth[v] + 1;
        }
      }
    }
  }
  int c = 0;
  for (int u : tord) {
    if (color[u] != 0)
      continue;
    queue<int> q;
    q.push(u);
    int k = 0;
    while (q.size() && k < B) {
      int v = q.front();
      q.pop();
      color[v] = c + 1;
      goUp[v] = par[u];
      top[v] = u;
      k++;
      for (int c : g[v]) {
        if (color[c] == 0)
          q.push(c);
      }
    }
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
  cin >> n;
  g.assign(n, {});
  rep(i, n) {
    int k;
    cin >> k;
    rep(j, k) {
      int c;
      cin >> c;
      g[i].emplace_back(c);
      par[c] = i;
    }
  }
  decomp(0);
  int q;
  cin >> q;
  rep(i, q) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v) << endl;
  }
}