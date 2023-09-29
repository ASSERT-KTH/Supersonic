#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define INF 999999999
vector<int> pass[6000];
int n, k;
int c[6000];
int r[6000];
int d[6000];

void dfs(int v, int u, int f, int end, vector<bool>& visited) {
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  for(auto &i : pass[u]) { 
    dfs(v, i, f + 1, end, visited); 
  }
}
int dijk(int s, int g) {
  fill(d, d+6000, INF);
  vector<bool> used(6000, false);
  d[s] = 0;
  while (1) {
    int v = -1;
    for(int u=0; u<n; u++) {
      if (!used[u] && (v == -1 || d[u] < d[v]))
        v = u;
    }
    if (v == -1)
      break;
    used[v] = true;
    for(auto &i : pass[v]) {
      vector<bool> visited(6000, false);
      dfs(v, i, 1, r[v], visited);
    }
  }
  return d[g];
}
int main() {
  cin >> n >> k;
  for(int i=0; i<n; i++) cin >> c[i] >> r[i];
  for(int i=0; i<k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].pb(b);
    pass[b].pb(a);
  }
  cout << dijk(0, n - 1) << endl;
}