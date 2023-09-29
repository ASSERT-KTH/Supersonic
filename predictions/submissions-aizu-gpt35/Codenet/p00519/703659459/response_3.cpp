#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6005;
vector<int> pass[MAXN];
int n, k, c[MAXN], r[MAXN], d[MAXN];
bool used[MAXN];
void dfs(int v, int u, int f, int end, bool visited[]) {
  if (visited[u]) return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end) return;
  for (auto i : pass[u]) dfs(v, i, f + 1, end, visited);
}
int dijk(int s, int g) {
  memset(d, 0x3f, sizeof(d));
  memset(used, false, sizeof(used));
  d[s] = 0;
  while (1) {
    int v = -1;
    for (int u = 0; u < n; u++)
      if (!used[u] && (v == -1 || d[u] < d[v]))
        v = u;
    if (v == -1) break;
    used[v] = true;
    for (auto i : pass[v]) {
      bool visited[MAXN] = {};
      dfs(v, i, 1, r[v], visited);
    }
  }
  return d[g];
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> c[i] >> r[i];
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].push_back(b);
    pass[b].push_back(a);
  }
  cout << dijk(0, n - 1) << '\n';
}