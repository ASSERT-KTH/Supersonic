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
const int MAXN = 1010;
int N, M;
vi g[MAXN], r[MAXN];
int used[MAXN];
int List[MAXN], l;
int cycle[MAXN], c;
int inCycle[MAXN];
ll dp[MAXN];
void dfs(int cur) {
  if (used[cur]) {
    int from = 0;
    while (List[from] != cur)
      from++;
    for (int i = from; i < l; i++) cycle[c++] = List[i];
    return;
  }
  used[cur] = 1;
  List[l++] = cur;
  if (sz(g[cur]) == 0) {
    cycle[c++] = cur;
    return;
  }
  rep(i, sz(g[cur])) { dfs(g[cur][i]); }
}
ll solve(int v) {
  ll &res = dp[v];
  if (res != -1)
    return res;
  used[v] = 1;
  res = 1;
  for (int i = 0; i < sz(r[v]); i++) res = res * solve(r[v][i]) % MOD;
  res = (res + 1) % MOD;
  return res;
}
ll f(int start) {
  l = 0;
  c = 0;
  dfs(start);
  ll res = 1;
  memset(inCycle, 0, sizeof(inCycle));
  for (int i = 0; i < c; i++) inCycle[cycle[i]] = 1;
  for (int i = 0; i < c; i++)
    for (int j = 0; j < sz(r[cycle[i]]); j++) {
      if (inCycle[r[cycle[i]][j]])
        continue;
      res = res * solve(r[cycle[i]][j]) % MOD;
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
  memset(dp, -1, sizeof(dp));
  ll ans = 1;
  memset(used, 0, sizeof(used));
  for (int i = 0; i < N; i++)
    if (!used[i]) { ans = ans * f(i) % MOD; }
  cout << ans << endl;
}