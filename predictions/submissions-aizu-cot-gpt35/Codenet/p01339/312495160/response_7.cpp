#include <iostream>
#include <vector>

#define MOD 1000000007LL

using namespace std;

int N, M;
vector<int> g[1010], r[1010];
int used[1010];
int cycle[1010], c;
ll dp[1010];

void dfs(int cur, vector<int>& list) {
  if (used[cur]) {
    int from = 0;
    while (list[from] != cur)
      from++;
    for (int i = from; i < list.size(); i++) {
      cycle[c++] = list[i];
    }
    return;
  }
  used[cur] = 1;
  list.push_back(cur);
  if (g[cur].empty()) {
    cycle[c++] = cur;
    return;
  }
  for (int i = 0; i < g[cur].size(); i++) {
    dfs(g[cur][i], list);
  }
}

ll solve(int v) {
  ll res = dp[v];
  if (res != -1)
    return res;
  used[v] = 1;
  res = 1;
  for (int i = 0; i < r[v].size(); i++) {
    res = res * solve(r[v][i]) % MOD;
  }
  res = (res + 1) % MOD;
  return res;
}

ll f(int start) {
  vector<int> list;
  c = 0;
  dfs(start, list);
  ll res = 1;
  int inCycle[1010] = {0};
  for (int i = 0; i < c; i++) {
    inCycle[cycle[i]] = 1;
  }
  for (int i = 0; i < c; i++) {
    for (int j = 0; j < r[cycle[i]].size(); j++) {
      if (inCycle[r[cycle[i]][j]])
        continue;
      res = res * solve(r[cycle[i]][j]) % MOD;
    }
  }
  res = (res + 1) % MOD;
  return res;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int s, d;
    cin >> s >> d;
    s--;
    d--;
    g[s].push_back(d);
    r[d].push_back(s);
  }
  ll ans = 1;
  for (int i = 0; i < N; i++) {
    if (!used[i]) {
      ans = ans * f(i) % MOD;
    }
  }
  cout << ans << endl;
}