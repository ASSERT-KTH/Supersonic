#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
constexpr int INF = 999999999;
vector<vector<int>> pass;
int n, k;
int c[6000];
int r[6000];
int d[6000];
bool used[6000];
void dfs(int v, int u, int f, int end) {
  if (used[u])
    return;
  used[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  for(int i = 0; i < pass[u].size(); ++i) {
    dfs(v, pass[u][i], f + 1, end);
  }
}
int dijk(int s, int g) {
  fill(d, d+6000, INF);
  fill(used, used+6000, false);
  d[s] = 0;
  while (1) {
    int v = -1;
    for(int u = 0; u < n; ++u) {
      if (!used[u] && (v == -1 || d[u] < d[v]))
        v = u;
    }
    if (v == -1)
      break;
    used[v] = true;
    fill(used, used+6000, false);
    for(int i = 0; i < pass[v].size(); ++i) {
      dfs(v, pass[v][i], 1, r[v]);
    }
  }
  return d[g];
}
int main() {
  cin >> n >> k;
  pass.resize(n);
  for(int i = 0; i < n; ++i) cin >> c[i] >> r[i];
  for(int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].push_back(b);
    pass[b].push_back(a);
  }
  cout << dijk(0, n - 1) << endl;
}