#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int B = 200;
int color[100010], par[100010], depth[100010];
int top[100010];
int goUp[100010];
bool vis[100010], vis2[100010];
int n;
vector<vector<int>> g;

void decomp() {
  for (int i = 0; i < n; i++) vis[i] = false, par[i] = -1;
  queue<int> q;
  q.push(0);

  int c = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (vis[v]) continue;
    vis[v] = true;

    int k = 0;
    queue<int> temp;
    temp.push(v);
    while (!temp.empty() && k < B) {
      int u = temp.front();
      temp.pop();
      vis2[u] = true;
      color[u] = c;
      goUp[u] = par[v];
      top[u] = v;
      k++;
      for (int c : g[u]) {
        if (!vis[c]) {
          temp.push(c);
          par[c] = u;
          depth[c] = depth[u] + 1;
        }
      }
    }
    while (!temp.empty()) temp.pop();
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
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int c;
      cin >> c;
      g[i].push_back(c);
    }
  }
  decomp();
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v) << endl;
  }
}