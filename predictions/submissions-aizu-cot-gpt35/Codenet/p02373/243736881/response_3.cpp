#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int* color;
int* par;
int* depth;
int* top;
int* goUp;
int n;
vector<vector<int>> g;
void decomp(int root) {
  rep(i, n) depth[i] = -1;
  queue<int> q;
  q.push(root);
  depth[root] = 0;
  int start = 0, end = 1;
  while (start < end) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (depth[v] == -1) {
        q.push(v);
        par[v] = u;
        depth[v] = depth[u] + 1;
        end++;
      }
    }
    start++;
  }
  int c = 0;
  rep(i, n) {
    if (depth[i] != -1 && color[i] == -1) {
      int u = i;
      while (u != -1) {
        color[u] = c;
        goUp[u] = par[u];
        top[u] = i;
        u = par[u];
      }
      c++;
    }
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
  cin >> n;
  g.assign(n, {});
  color = new int[n];
  par = new int[n];
  depth = new int[n];
  top = new int[n];
  goUp = new int[n];
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
  fill(color, color + n, -1);
  decomp(0);
  int q;
  cin >> q;
  rep(i, q) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v) << endl;
  }
  delete[] color;
  delete[] par;
  delete[] depth;
  delete[] top;
  delete[] goUp;
}