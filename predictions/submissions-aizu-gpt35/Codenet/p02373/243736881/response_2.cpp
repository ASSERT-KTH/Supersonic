#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int color[100010], par[100010], depth[100010];
int top[100010];
int N, B;
int goUp[100010];
bool vis[100010];
vector<vector<int>> g;
vector<int> tord;
vector<int> parent;
void decomp(int root) {
  vis[root] = true;
  tord.push_back(root);
  int c = tord.size() / B;
  color[root] = c;
  if (tord.size() % B == 0) {
    parent.push_back(par[root]);
    top[c] = root;
    for (int i = tord.size() - B; i < tord.size(); i++) {
      goUp[tord[i]] = parent.back();
    }
  }

  for (int c : g[root]) {
    if (!vis[c]) {
      par[c] = root;
      depth[c] = depth[root] + 1;
      decomp(c);
    }
  }
}
int solve(int u, int v) {
  while (color[u] != color[v]) {
    if (depth[top[color[u]]] > depth[top[color[v]]]) {
      swap(u, v);
    }
    u = goUp[top[color[u]]];
  }
  while (u != v) {
    if (depth[u] > depth[v]) {
      swap(u, v);
    }
    v = par[v];
  }
  return u;
}
int main() {
  cin >> N;
  g.resize(N);
  rep(i, N) {
    int k;
    cin >> k;
    rep(j, k) {
      int c;
      cin >> c;
      g[i].push_back(c);
      par[c] = i;
    }
  }
  B = sqrt(N);
  decomp(0);
  int q;
  cin >> q;
  rep(i, q) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v) << endl;
  }
}