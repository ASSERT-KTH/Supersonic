#include <iostream>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

const int INF = 1070000000LL;
const int MOD = 1000000007LL;

int N, M;
vi g[1010], r[1010];
int used[1010];
int List[1010], l;
int cycle[1010], c;
int inCycle[1010];
ll dp[1010];

void dfs(int cur) {
  used[cur] = 1;
  List[l++] = cur;
  for(int i = 0; i < g[cur].size(); i++) {
    if(used[g[cur][i]]) {
      int from = 0;
      while (List[from] != g[cur][i])
        from++;
      for(int j = from; j < l; j++)
        cycle[c++] = List[j];
      return;
    }
    dfs(g[cur][i]);
  }
  if(g[cur].empty())
    cycle[c++] = cur;
}

ll solve(int v) {
  ll &res = dp[v];
  if (res != -1)
    return res;
  used[v] = 1;
  res = 1;
  for(int i = 0; i < r[v].size(); i++)
    res = res * solve(r[v][i]) % MOD;
  res = (res + 1) % MOD;
  return res;
}

ll f(int start) {
  l = 0;
  c = 0;
  dfs(start);
  ll res = 1;
  for(int i = 0; i < c; i++) inCycle[cycle[i]] = 1;
  for(int i = 0; i < c; i++)
    for(int j = 0; j < r[cycle[i]].size(); j++)
      if (!inCycle[r[cycle[i]][j]])
        res = res * solve(r[cycle[i]][j]) % MOD;
  res = (res + 1) % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int s, d;
    cin >> s >> d;
    s--;
    d--;
    g[s].push_back(d);
    r[d].push_back(s);
  }
  memset(dp, -1, sizeof(dp));
  ll ans = 1;
  for(int i = 0; i < N; i++)
    if (!used[i])
      ans = ans * f(i) % MOD;
  cout << ans << endl;
}