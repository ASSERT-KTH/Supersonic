#include <algorithm>
#include <cassert>
#include <iostream>
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
  int q[100010];
  int front = 0, rear = 0;
  q[rear++] = root;
  vector<int> tord;
  while (front != rear) {
    int v = q[front++];
    vis[v] = true;
    tord.push_back(v);
    for (int c : g[v]) {
      if (!vis[c]) {
        q[rear++] = c;
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
    q[rear++] = u;
    int k = 0;
    while (front != rear && k < B) {
      int v = q[front++];
      vis[v] = true;
      color[v] = c;
      goUp[v] = par[u];
      top[v] = u;
      k++;
      for (int c : g[v]) {
        if (!vis[c])
          q[rear++] = c;
      }
    }
    c++;
  }
}
int solve(int u, int v) {
  while (u != v && u != -1 && v != -1) {
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
    cout << solve(u, v) << endl;
  }
}