#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

typedef long long ll;

int N, M;
vector<int> g[1010], r[1010];
vector<int> used(1010), List(1010), cycle(1010), inCycle(1010);
vector<ll> dp(1010);

void dfs(int cur) {
  if (used[cur]) {
    int from = 0;
    while (List[from] != cur)
      from++;
    for (int i = from; i < List.size(); i++) {
      cycle.push_back(List[i]);
    }
    return;
  }
  used[cur] = 1;
  List.push_back(cur);
  if (g[cur].empty()) {
    cycle.push_back(cur);
    return;
  }
  for (int i = 0; i < g[cur].size(); i++) {
    dfs(g[cur][i]);
  }
}

void solve(int v, ll& res) {
  if (dp[v] != -1)
    return;
  used[v] = 1;
  res = 1;
  for (int i = 0; i < r[v].size(); i++) {
    solve(r[v][i], res);
    res = (res * dp[r[v][i]]) % MOD;
  }
  res = (res + 1) % MOD;
  dp[v] = res;
}

ll f(int start) {
  List.clear();
  cycle.clear();
  dfs(start);
  ll res = 1;
  inCycle.assign(1010, 0);
  for (int i = 0; i < cycle.size(); i++) {
    inCycle[cycle[i]] = 1;
  }
  for (int i = 0; i < cycle.size(); i++) {
    for (int j = 0; j < r[cycle[i]].size(); j++) {
      if (inCycle[r[cycle[i]][j]])
        continue;
      solve(r[cycle[i]][j], res);
      res = (res * dp[r[cycle[i]][j]]) % MOD;
    }
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
  dp.assign(1010, -1);
  ll ans = 1;
  for (int i = 0; i < N; i++) {
    if (!used[i]) {
      ll res = 0;
      ans = (ans * f(i)) % MOD;
    }
  }
  cout << ans << endl;
}