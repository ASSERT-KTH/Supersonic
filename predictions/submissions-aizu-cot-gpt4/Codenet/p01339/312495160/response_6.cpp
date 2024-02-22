#include <bits/stdc++.h>
#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it, X) for (auto it = (X).begin(); it != (X).end(); it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())
using namespace std;
typedef istringstream iss;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;
int N, M;
vi g[1010], r[1010];
int used[1010];
int List[1010], l;
int cycle[1010], c;
int inCycle[1010];
ll dp[1010];
void dfs(int cur) {
  if (used[cur]) {
    int from = 0;
    while (List[from] != cur)
      from++;
    rep2(i, from, l) { cycle[c++] = List[i]; }
    return;
  }
  used[cur] = 1;
  List[l++] = cur;
  int g_cur_size = sz(g[cur]);
  if (g_cur_size == 0) {
    cycle[c++] = cur;
    return;
  }
  rep(i, g_cur_size) { dfs(g[cur][i]); }
}
ll solve(int v) {
  ll &res = dp[v];
  if (res != -1)
    return res;
  used[v] = 1;
  res = 1;
  int r_v_size = sz(r[v]);
  rep(i, r_v_size) { res = res * solve(r[v][i]) % MOD; }
  res = (res + 1) % MOD;
  return res;
}
ll f(int start) {
  l = 0;
  c = 0;
  dfs(start);
  ll res = 1;
  int c_size = c;
  rep(i, c_size) inCycle[cycle[i]] = 1;
  rep(i, c_size) {
    int r_cycle_i_size = sz(r[cycle[i]]);
    rep(j, r_cycle_i_size) {
      if (inCycle[r[cycle[i]][j]])
        continue;
      res = res * solve(r[cycle[i]][j]) % MOD;
    }
  }
  res = (res + 1) % MOD;
  return res;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  g->reserve(M);
  r->reserve(M);
  rep(i, N) dp[i] = -1;
  ll ans = 1;
  rep(i, N) if (!used[i]) { ans = ans * f(i) % MOD; }
  cout << ans << endl;
}