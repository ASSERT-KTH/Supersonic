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
vector<int> bfs(int v) {
  bool visited[6000] = {};
  vector<int> vec;
  queue<pii> que;
  que.push(pii(v, 0));
  while (!que.empty()) {
    pii p = que.front();
    que.pop();
    if (visited[p.first])
      continue;
    visited[p.first] = true;
    vec.pb(p.first);
    if (p.second >= r[v])
      continue;
    rep(i, pass[p.first].size()) { que.push(pii(pass[p.first][i], p.second + 1)); }
  }
  return vec;
}
int dijk(int s, int g) {
  rep(i, 6000) d[i] = INF;
  d[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> que;
  que.push(pii(0, s));
  while (!que.empty()) {
    pii p = que.top();
    que.pop();
    if (d[p.second] < p.first)
      continue;
    vi vec = bfs(p.second);
    rep(i, vec.size()) {
      if (d[vec[i]] > d[p.second] + c[p.second]) {
        d[vec[i]] = d[p.second] + c[p.second];
        que.push(pii(d[vec[i]], vec[i]));
      }
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