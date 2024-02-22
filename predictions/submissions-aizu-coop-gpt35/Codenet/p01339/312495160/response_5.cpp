#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

#define MOD 1000000007

using namespace std;

typedef vector<int> vi;

int N, M;
vi g[1010], r[1010];
stack<int> st;
int dp[1010];

void dfs(int cur) {
  st.push(cur);

  while (!st.empty()) {
    int cur = st.top();
    st.pop();

    if (cur >= 0) {
      if (dp[cur] != -1) {
        st.push(-dp[cur]);
        continue;
      }

      dp[cur] = 0;
      st.push(-cur);

      for (int i = 0; i < r[cur].size(); i++) {
        int next = r[cur][i];
        if (dp[next] == -1) {
          st.push(next);
        }
      }
    } else {
      cur = -cur;
      int res = 1;

      for (int i = 0; i < g[cur].size(); i++) {
        int next = g[cur][i];
        res = (res * (dp[next] + 1)) % MOD;
      }

      dp[cur] = res;
    }
  }
}

int f(int start) {
  int res = 1;
  dfs(start);

  while (!st.empty()) {
    int cur = st.top();
    st.pop();
    cur = -cur;

    if (cur < 0)
      continue;

    for (int i = 0; i < r[cur].size(); i++) {
      int next = r[cur][i];
      if (next >= N)
        res = (res * (dp[next] + 1)) % MOD;
    }
  }

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

  int ans = 1;

  for (int i = 0; i < N; i++) {
    if (dp[i] == -1)
      ans = (ans * f(i)) % MOD;
  }

  cout << ans << endl;
}