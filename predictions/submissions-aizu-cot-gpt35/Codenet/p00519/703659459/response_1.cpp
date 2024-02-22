#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> pass;
vector<int> c, r, d;
int n, k;

void dfs(int v, int u, int f, int end) {
  if (d[u] <= d[v] + c[v]) {
    return;
  }
  d[u] = d[v] + c[v];
  if (f >= end) {
    return;
  }
  for (int i = 0; i < pass[u].size(); i++) {
    dfs(v, pass[u][i], f + 1, end);
  }
}

int dijk(int s, int g) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, s});
  d[s] = 0;
  while (!pq.empty()) {
    int dist = pq.top().first;
    int u = pq.top().second;
    pq.pop();
    if (dist > d[u]) {
      continue;
    }
    for (int i = 0; i < pass[u].size(); i++) {
      dfs(u, pass[u][i], 1, r[u]);
    }
    for (int i = 0; i < pass[u].size(); i++) {
      int v = pass[u][i];
      if (d[u] + c[u] < d[v]) {
        d[v] = d[u] + c[u];
        pq.push({d[v], v});
      }
    }
  }
  return d[g];
}

int main() {
  cin >> n >> k;
  pass.resize(n);
  c.resize(n);
  r.resize(n);
  d.resize(n, INT_MAX);
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