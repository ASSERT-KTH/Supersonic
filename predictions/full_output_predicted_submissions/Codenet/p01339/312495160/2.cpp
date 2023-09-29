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
  if (sz(g[cur]) == 0) {
    cycle[c++] = cur;
    return;
  }
  rep(i, sz(g[cur]) == 0) { dfs(g[cur][i]); }
}
ll solve(int v) {
  ll &res = dp[v];
  if (res != -1)
    return res;
  used[v] = 1;
  res = 1;
  rep(i, sz(r[v])) { res = res *