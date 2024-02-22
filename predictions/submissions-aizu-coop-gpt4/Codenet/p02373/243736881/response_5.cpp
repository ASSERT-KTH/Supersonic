#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
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
  list<int> q;
  q.push_back(root);
  int c = 0;
  while (!q.empty()) {
    int batchSize = min((int)q.size(), B);
    for (int i = 0; i < batchSize; i++) {
      int v = q.front();
      q.pop_front();
      vis[v] = true;
      color[v] = c;
      goUp[v] = par[root];
      top[v] = root;
      for (int child : g[v]) {
        if (!vis[child]) {
          q.push_back(child);
          par[child] = v;
          depth[child] = depth[v] + 1;
        }
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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