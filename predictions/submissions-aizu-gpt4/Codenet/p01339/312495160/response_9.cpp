#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
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
    for (int from = 0; List[from] != cur; from++)
      cycle[c++] = List[from];
    return;
  }
  used[cur] = 1;
  List[l++] = cur;
  if (g[cur].empty()) {
    cycle[c++] = cur;
    return;
  }
  for (auto i : g[cur]) dfs(i);
}
ll solve(int v) {
  ll &res = dp[v];
  if (res != -1)
    return res;
  used[v] = 1;
  res = 1;
  for (auto i : r[v]) res = res * solve(i) % MOD;
  return (res + 1) % MOD;
}
ll f(int start) {
  l = 0;
  c = 0;
  dfs(start);
  ll res = 1;
  for (int i = 0; i < c; i++) inCycle[cycle[i]] = 1;
  for (int i = 0; i < c; i++) 
    for (auto j : r[cycle[i]]) 
      if (!inCycle[j])
        res = res * solve(j) % MOD;
  return (res + 1) % MOD;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int s, d;
    cin >> s >> d;
    s--;
    d--;
    g[s].push_back(d);
    r[d].push_back(s);
  }
  memset(dp, -1, sizeof(dp));
  ll ans = 1;
  for (int i = 0; i < N; i++) 
    if (!used[i]) 
      ans = ans * f(i) % MOD;
  cout << ans << endl;
  return 0;
}