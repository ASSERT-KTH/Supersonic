#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

constexpr double EPS = 1e-9;
constexpr ll INF = 1070000000LL;
constexpr ll MOD = 1000000007LL;

#define fir first
#define foreach(it, X) for (typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define mt make_tuple
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

int N, M;
vi g[1010], r[1010];

void dfs(int cur, int* used, int* List, int &l, int* cycle, int &c) {
  if (used[cur]) {
    int from = 0;
    while (List[from] != cur)
      from++;
    rep2(i, from, l) { cycle[c++] = List[i]; }
    return;
  }
  used[cur] = 1;
  List[l++] = cur;
  if (sz(g[cur]) == 0) {
    cycle[c++] = cur;
    return;
  }
  rep(i, sz(g[cur])) { dfs(g[cur][i], used, List, l, cycle, c); }
}

ll solve(int v, int* used, ll* dp) {
  ll &res = dp[v];
  if (res != -1)
    return res;
  used[v] = 1;
  res = 1;
  rep(i, sz(r[v])) { res = res * solve(r[v][i], used, dp) % MOD; }
  res = (res + 1) % MOD;
  return res;
}

ll f(int start, int* used, ll* dp, int* inCycle) {
  int List[1010], l = 0, cycle[1010], c = 0;
  dfs(start, used, List, l, cycle, c);
  ll res = 1;
  rep(i, c) inCycle[cycle[i]] = 1;
  rep(i, c) rep(j, sz(r[cycle[i]])) {
    if (inCycle[r[cycle[i]][j]])
      continue;
    res = res * solve(r[cycle[i]][j], used, dp) % MOD;
  }
  res = (res + 1) % MOD;
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  rep(i, M) {
    int s, d;
    cin >> s >> d;
    s--;
    d--;
    g[s].pb(d);
    r[d].pb(s);
  }
  int used[1010] = {0}, inCycle[1010] = {0};
  ll dp[1010];
  fill(dp, dp+1010, -1);
  ll ans = 1;
  rep(i, N) if (!used[i]) { ans = ans * f(i, used, dp, inCycle) % MOD; }
  cout << ans << endl;
}