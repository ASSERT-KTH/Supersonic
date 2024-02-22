#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vi;
const int maxN = 1010;
const long long MOD = 1000000007LL;
int N, M;
vi g[maxN], r[maxN];
int used[maxN];
int List[maxN], l;
int cycle[maxN], c;
int inCycle[maxN];
long long dp[maxN];

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

long long solve(int v) {
  long long &res = dp[v];
  if (res != -1)
    return res;
  used[v] = 1;
  res = 1;
  for (int i = 0; i < r[v].size(); i++) { res = res * solve(r[v][i]) % MOD; }
  res = (res + 1) % MOD;
  return res;
}

long long f(int start) {
  l = 0;
  c = 0;
  dfs(start);
  long long res = 1;
  for (int i = 0; i < c; i++) inCycle[cycle[i]] = 1;
  for (int i = 0; i < c; i++) 
    for (int j = 0; j < r[cycle[i]].size(); j++) {
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
  for (int i = 0; i < M; i++) {
    int s, d;
    cin >> s >> d;
    s--;
    d--;
    g[s].push_back(d);
    r[d].push_back(s);
  }
  memset(dp, -1, sizeof(dp));
  long long ans = 1;
  for (int i = 0; i < N; i++) if (!used[i]) { ans = ans * f(i) % MOD; }
  cout << ans << endl;
}