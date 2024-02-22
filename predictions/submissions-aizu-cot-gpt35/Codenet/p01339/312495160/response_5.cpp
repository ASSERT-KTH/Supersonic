#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MOD = 1000000007;

int N, M;
vector<int> g[1010], r[1010];
vector<int> used(1010), List(1010), cycle, inCycle(1010);
vector<long long> dp(1010);

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

long long solve(int v) {
  long long res = 1;
  vector<int> stack;
  stack.push_back(v);
  while (!stack.empty()) {
    int cur = stack.back();
    if (used[cur]) {
      stack.pop_back();
      res = (res * (dp[cur] + 1)) % MOD;
      continue;
    }
    used[cur] = 1;
    stack.push_back(cur);
    for (int i = 0; i < r[cur].size(); i++) {
      stack.push_back(r[cur][i]);
    }
  }
  return res;
}

long long f(int start) {
  List.clear();
  cycle.clear();
  dfs(start);
  long long res = 1;
  unordered_set<int> cycleSet(cycle.begin(), cycle.end());
  for (int i = 0; i < cycle.size(); i++) {
    for (int j = 0; j < r[cycle[i]].size(); j++) {
      if (cycleSet.count(r[cycle[i]][j])) {
        continue;
      }
      res = (res * solve(r[cycle[i]][j])) % MOD;
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
  long long ans = 1;
  for (int i = 0; i < N; i++) {
    if (!used[i]) {
      ans = (ans * f(i)) % MOD;
    }
  }
  cout << ans << endl;
}