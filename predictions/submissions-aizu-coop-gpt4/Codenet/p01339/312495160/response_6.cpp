#include <bits/stdc++.h>
#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define pb push_back
#define sz(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
int N, M;

ll solve(int v, vi r[], ll dp[], int used[]) {
  ll &res = dp[v];
  if (res != -1)
    return res;
  used[v] = 1;
  res = 1;
  rep(i, sz(r[v])) { res = res * solve(r[v][i], r, dp, used) % MOD; }
  res = (res + 1) % MOD;
  return res;
}

ll dfs_and_solve(int start, vi g[], vi r[]) {
  vector<int> List, cycle;
  int l = 0, c = 0;
  int used[1010] = {0}, inCycle[1010] = {0};
  stack<int> s;
  s.push(start);
  while(!s.empty()) {
    int cur = s.top(); s.pop();
    if (used[cur]) {
      int from = 0;
      while (List[from] != cur)
        from++;
      rep2(i, from, l) { cycle[c++] = List[i]; }
      continue;
    }
    used[cur] = 1;
    List[l++] = cur;
    if (sz(g[cur]) != 0) 
      s.push(g[cur][0]);
    else
      cycle[c++] = cur;
  }

  ll res = 1;
  rep(i, c) inCycle[cycle[i]] = 1;
  ll dp[1010];
  fill_n(dp, 1010, -1);
  rep(i, c) rep(j, sz(r[cycle[i]])) {
    if (inCycle[r[cycle[i]][j]])
      continue;
    res = res * solve(r[cycle[i]][j], r, dp, used) % MOD;
  }
  res = (res + 1) % MOD;
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  vi g[1010], r[1010];
  int used[1010] = {0};
  rep(i, M) {
    int s, d;
    cin >> s >> d;
    s--;
    d--;
    g[s].pb(d);
    r[d].pb(s);
  }
  ll ans = 1;
  rep(i, N) if (!used[i]) { ans = ans * dfs_and_solve(i, g, r) % MOD; }
  cout << ans << endl;
  return 0;
}