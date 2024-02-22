#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

vector<int> pass[6000];
vector<int> c(6000);
vector<int> r(6000);
vector<int> d(6000, numeric_limits<int>::max());
vector<bool> used(6000);
vector<bool> visited(6000);

void dfs(int v, int u, int f, int end) {
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  rep(i, pass[u].size()) { dfs(v, pass[u][i], f + 1, end); }
}

int dijk(int s, int g) {
  fill(d.begin(), d.end(), numeric_limits<int>::max());
  fill(used.begin(), used.end(), false);
  d[s] = 0;
  while (1) {
    int v = -1;
    rep(u, n) {
      if (!used[u] && (v == -1 || d[u] < d[v]))
        v = u;
    }
    if (v == -1)
      break;
    used[v] = true;
    fill(visited.begin(), visited.end(), false);
    rep(i, pass[v].size()) {
      dfs(v, pass[v][i], 1, r[v]);
    }
  }
  return d[g];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  rep(i, n) cin >> c[i] >> r[i];
  rep(i, k) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].push_back(b);
    pass[b].push_back(a);
  }
  cout << dijk(0, n - 1) << endl;
}