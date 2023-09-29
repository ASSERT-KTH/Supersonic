#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 1010
vector<int> g[MAXN], r[MAXN];
int used[MAXN], inCycle[MAXN];
int List[MAXN], cycle[MAXN];
int dp[MAXN];
int l, c;
void dfs(int cur) {
  if (used[cur]) {
    int from = 0;
    while (List[from] != cur)
      from++;
    for (int i = from; i < l; i++) { cycle[c++] = List[i]; }
    return;
  }
  used[cur] = 1;
  List[l++] = cur;
  if (g[cur].empty()) {
    cycle[c++] = cur;
    return;
  }
  for (int i = 0; i < g[cur].size(); i++) { dfs(g[cur][i]); }
}
int solve(int v) {
  int &res = dp[v];
  if (res != -1)
    return res;
  used[v] = 1;
  res = 1;
  for (int i = 0; i < r[v].size(); i++) { res = (1LL * res * solve(r[v][i])) % MOD; }
  res = (1LL * res + 1) % MOD;
  return res;
}
int f(int start) {
  l = c = 0;
  dfs(start);
  int res = 1;
  for (int i = 0; i < c; i++) inCycle[cycle[i]] = 1;
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r[cycle[i]].size(); j++) {
      if (inCycle[r[cycle[i]][j]])
        continue;
      res = (1LL * res * solve(r[cycle[i]][j])) % MOD;
    }
  }
  res = (1LL * res + 1) % MOD;
  return res;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  memset(dp, -1, sizeof(dp));
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int s, d;
    cin >> s >> d;
    s--, d--;
    g[s].push_back(d);
    r[d].push_back(s);
  }
  int ans = 1;
  for (int i = 0; i < N; i++) if (!used[i]) { ans = (1LL * ans * f(i)) % MOD; }
  cout << ans << endl;
  return 0;
}