#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int N, M;
vector<int> g[1010], r[1010];

void dfs(int cur, int* used, vector<int>& List, vector<int>& cycle) {
  if (used[cur]) {
    int from = 0;
    while (List[from] != cur) {
      from++;
    }
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
    dfs(g[cur][i], used, List, cycle);
  }
}

long long solve(int v, int* used, vector<long long>& dp) {
  long long& res = dp[v];
  if (res != -1) {
    return res;
  }
  used[v] = 1;
  res = 1;
  for (int i = 0; i < r[v].size(); i++) {
    res = res * solve(r[v][i], used, dp) % MOD;
  }
  res = (res + 1) % MOD;
  return res;
}

long long f(int start, vector<int>& cycle, vector<int>& inCycle, vector<long long>& dp) {
  vector<int> List;
  dfs(start, inCycle.data(), List, cycle);
  long long res = 1;
  for (int i = 0; i < cycle.size(); i++) {
    inCycle[cycle[i]] = 1;
  }
  for (int i = 0; i < cycle.size(); i++) {
    for (int j = 0; j < r[cycle[i]].size(); j++) {
      if (inCycle[r[cycle[i]][j]]) {
        continue;
      }
      res = res * solve(r[cycle[i]][j], dp.data(), dp) % MOD;
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
  vector<long long> dp(N, -1);
  long long ans = 1;
  vector<int> used(N, 0);
  for (int i = 0; i < N; i++) {
    if (!used[i]) {
      vector<int> cycle, inCycle(N, 0);
      ans = ans * f(i, cycle, inCycle, dp) % MOD;
    }
  }
  cout << ans << endl;
  return 0;
}