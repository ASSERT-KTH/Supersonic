#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6005;
typedef vector<int> vi;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define INF 999999999
vector<int> pass[MAXN];
int n, k;
int c[MAXN];
int r[MAXN];
int d[MAXN];
bool used[MAXN];
bitset<MAXN> visited;
void dfs(int v, int u, int f, int end) {
  if (visited[u] || f >= end) return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  for (int i : pass[u]) dfs(v, i, f + 1, end);
}
int dijk(int s, int g) {
  fill_n(d, n, INF); fill_n(used, n, false);
  d[s] = 0;
  while (1) {
    int v = -1;
    for (int u = 0; u < n; ++u)
      if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
    if (v == -1) break;
    used[v] = true; visited.reset();
    for (int i : pass[v]) dfs(v, i, 1, r[v]);
  }
  return d[g];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> c[i] >> r[i];
  for (int i = 0; i < k; ++i) {
    int a, b; cin >> a >> b; --a, --b;
    pass[a].pb(b); pass[b].pb(a);
  }
  cout << dijk(0, n - 1) << endl;
}