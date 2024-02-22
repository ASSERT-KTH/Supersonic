#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef vector<int> vi;

vector<vi> pass;
vi c, r, d, used;

void dfs(int v, int u, int f, int end, vi& visited) {
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  for (int i = 0; i < pass[u].size(); i++) {
    dfs(v, pass[u][i], f + 1, end, visited);
  }
}

int dijk(int s, int g) {
  int n = pass.size();
  d.assign(n, numeric_limits<int>::max());
  used.assign(n, false);
  d[s] = 0;
  while (true) {
    int v = -1;
    for (int u = 0; u < n; u++) {
      if (!used[u] && (v == -1 || d[u] < d[v]))
        v = u;
    }
    if (v == -1)
      break;
    used[v] = true;
    for (int i = 0; i < pass[v].size(); i++) {
      vi visited(n, false);
      dfs(v, pass[v][i], 1, r[v], visited);
    }
  }
  return d[g];
}

int main() {
  int n, k;
  cin >> n >> k;
  c.resize(n);
  r.resize(n);
  pass.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i] >> r[i];
  }
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].push_back(b);
    pass[b].push_back(a);
  }
  cout << dijk(0, n - 1) << endl;
}