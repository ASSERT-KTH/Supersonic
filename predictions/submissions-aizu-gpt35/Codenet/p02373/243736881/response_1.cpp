#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int N = 1e5 + 10, B = 200;
int color[N], par[N], depth[N], top[N], goUp[N];
bool vis[N];
int n;
vector<int> g[N];
void decomp(int root) {
    rep(i, n) vis[i] = false, par[i] = -1;
    vector<int> tord;
    tord.reserve(n);
    tord.push_back(root);
    vis[root] = true;
    rep(i, tord.size()) {
        int v = tord[i];
        for (int c : g[v]) {
            if (!vis[c]) {
                tord.push_back(c);
                vis[c] = true;
                par[c] = v;
                depth[c] = depth[v] + 1;
            }
        }
    }
    rep(i, n) vis[i] = false;
    int c = 0;
    rep(i, tord.size()) {
        int u = tord[i];
        if (vis[u]) continue;
        vis[u] = true;
        goUp[u] = par[u];
        top[u] = u;
        color[u] = c;
        int k = 0;
        for (int j = i; j < tord.size() && k < B; j++) {
            int v = tord[j];
            if (vis[v]) continue;
            vis[v] = true;
            color[v] = c;
            goUp[v] = par[u];
            top[v] = u;
            k++;
        }
        c++;
    }
}
int solve(int u, int v) {
  while (color[u] != color[v]) {
    if (depth[top[u]] > depth[top[v]]) u = goUp[u];
    else v = goUp[v];
  }
  while (u != v) {
    if (depth[u] > depth[v]) u = par[u];
    else v = par[v];
  }
  return u;
}
int main() {
  memset(vis, false, sizeof(vis));
  cin >> n;
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