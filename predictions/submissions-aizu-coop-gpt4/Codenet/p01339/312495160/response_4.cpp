#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

ll solve(int v, vi* r, int* used, ll* dp) {
  ll &res = dp[v];
  if (res != -1)
    return res;
  used[v] = 1;
  res = 1;
  for(auto &i : r[v]) { res = res * solve(i, r, used, dp) % MOD; }
  res = (res + 1) % MOD;
  return res;
}

ll f(int start, vi* g, vi* r, int* used, ll* dp, int* inCycle, int* List, int* cycle) {
  int l = 0;
  int c = 0;
  stack<int> st;
  st.push(start);
  while(!st.empty()) {
    int cur = st.top();
    st.pop();
    if (used[cur]) {
      int from = 0;
      while (List[from] != cur) from++;
      for(int i = from; i < l; i++) cycle[c++] = List[i];
      return c;
    }
    used[cur] = 1;
    List[l++] = cur;
    for(auto &i : g[cur]) st.push(i);
  }
  cycle[c++] = start;
  return c;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vi g[N], r[N];
  for(int i = 0; i < M; i++) {
    int s, d;
    cin >> s >> d;
    s--; d--;
    g[s].push_back(d);
    r[d].push_back(s);
  }

  ll dp[N];
  fill(dp, dp + N, -1);
  int used[N], inCycle[N], List[N], cycle[N];
  fill(used, used + N, 0);
  fill(inCycle, inCycle + N, 0);
  
  ll ans = 1;
  for(int i = 0; i < N; i++) {
    if (!used[i]) {
      int c = f(i, g, r, used, dp, inCycle, List, cycle);
      ll res = 1;
      for(int j = 0; j < c; j++) inCycle[cycle[j]] = 1;
      for(int j = 0; j < c; j++) {
        for(auto &k : r[cycle[j]]) {
          if (inCycle[k]) continue;
          res = res * solve(k, r, used, dp) % MOD;
        }
      }
      res = (res + 1) % MOD;
      ans = ans * res % MOD;
    }
  }
  cout << ans << endl;
}