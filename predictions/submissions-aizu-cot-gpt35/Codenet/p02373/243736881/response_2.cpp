#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int B = 200;

int n;
vector<vector<int>> g;
vector<int> color, par, depth, top, goUp;

void decomp(int root) {
  queue<int> q;
  q.push(root);
  vector<int> tord;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    tord.push_back(v);
    for (int c : g[v]) {
      if (par[c] == -1) {
        q.push(c);
        par[c] = v;
        depth[c] = depth[v] + 1;
      }
    }
  }
  int c = 0;
  for (int u : tord) {
    if (color[u] == -1) {
      q.push(u);
      int k = 0;
      while (!q.empty() && k < B) {
        int v = q.front();
        q.pop();
        color[v] = c;
        goUp[v] = par[u];
        top[v] = u;
        k++;
        for (int c : g[v]) {
          if (color[c] == -1)
            q.push(c);
        }
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
  color.assign(n, -1);
  par.assign(n, -1);
  depth.assign(n, 0);
  top.assign(n, -1);
  goUp.assign(n, -1);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int c;
      cin >> c;
      g[i].push_back(c);
      par[c] = i;
    }
  }
  decomp(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v) << endl;
  }
}