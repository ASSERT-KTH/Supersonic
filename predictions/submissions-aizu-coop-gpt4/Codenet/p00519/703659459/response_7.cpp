#include "bits/stdc++.h"
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
bool used[6000];
void dfs(int v, int u, int f, int end, bool (&visited)[6000]) { // pass visited by reference
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  rep(i, pass[u].size()) { dfs(v, pass[u][i], f + 1, end, visited); }
}
int dijk(int s, int g) {
  priority_queue<pii, vector<pii>, greater<pii>> q; // use a priority queue to select the next node to process
  fill(d, d+6000, INF); // initialize all distances to INF
  fill(used, used+6000, false); // initialize all nodes as unvisited
  d[s] = 0; 
  q.push({0, s});
  while (!q.empty()) {
    int v = q.top().second; q.pop();
    if (used[v]) continue; // skip nodes that have already been visited
    used[v] = true;
    for(auto i: pass[v]) {
      bool visited[6000] = {};
      dfs(v, i, 1, r[v], visited);
      if (d[i] != INF) // if the node has been visited, push it into the queue
        q.push({d[i], i});
    }
  }
  return d[g];
}
int main() {
  cin >> n >> k;
  rep(i, n) cin >> c[i] >> r[i];
  rep(i, k) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].pb(b);
    pass[b].pb(a);
  }
  cout << dijk(0, n - 1) << endl;
}