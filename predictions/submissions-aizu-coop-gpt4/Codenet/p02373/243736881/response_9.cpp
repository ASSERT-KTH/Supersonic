#include <cstdio>
#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
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
  vector<int> tord;
  tord.reserve(n);  // Pre-allocate space for tord
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
    queue<int>().swap(q);  // Clear the queue in constant time
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
  scanf("%d", &n);  // Use scanf instead of cin for faster I/O
  g.assign(n, {});
  rep(i, n) {
    int k;
    scanf("%d", &k);  // Use scanf instead of cin for faster I/O
    rep(j, k) {
      int c;
      scanf("%d", &c);  // Use scanf instead of cin for faster I/O
      g[i].push_back(c);
      par[c] = i;
    }
  }
  decomp(0);
  int q;
  scanf("%d", &q);  // Use scanf instead of cin for faster I/O
  rep(i, q) {
    int u, v;
    scanf("%d%d", &u, &v);  // Use scanf instead of cin for faster I/O
    printf("%d\n", solve(u, v));  // Use printf instead of cout for faster I/O
  }
}