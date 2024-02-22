#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define INF numeric_limits<int>::max()

vector<vector<int>> pass;
vector<int> c, r, d;
vector<bool> used;

void dfs(int v, int u, int f, int end, bool visited) {
  if (visited[u]) return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end) return;
  for (int neighbor : pass[u]) {
    dfs(v, neighbor, f + 1, end, visited);
  }
}

int dijk(int s, int g) {
  int n = pass.size();
  d.assign(n, INF);
  used.assign(n, false);
  d[s] = 0;
  while (1) {
    int v = -1;
    rep(u, n) {
      if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }
    if (v == -1) break;
    used[v] = true;
    for (int neighbor : pass[v]) {
      vector<bool> visited(n, false);
      dfs(v, neighbor, 1, r[v], visited);
    }
  }
  return d[g];
}

int main() {
  int n, k;
  cin >> n >> k;
  c.resize(n);
  r.resize(n);
  rep(i, n) cin >> c[i] >> r[i];
  pass.resize(n);
  rep(i, k) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].pb(b);
    pass[b].pb(a);
  }
  cout << dijk(0, n - 1) << endl;
  return 0;
}