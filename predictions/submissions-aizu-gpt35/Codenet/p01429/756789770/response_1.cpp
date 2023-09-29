#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;
using ll = long long;
constexpr ll INF = 1e18;
constexpr int MAXN = 2005, MAXM = 100005;
ll sum[MAXM];
ll dp[MAXN][MAXN];
int notes[MAXN];
ll beauty[MAXM];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  ll f;
  while (cin >> n >> m >> f) {
    for (int i = 0; i < n; i++) {
      cin >> notes[i];
      notes[i]--;
    }
    for (int i = 0; i < m; i++) {
      cin >> beauty[i];
    }
    sum[0] = beauty[0];
    for (int i = 1; i < m; i++) {
      sum[i] = sum[i - 1] + beauty[i];
    }
    sort(notes, notes + n, greater<int>());
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      int next = i + 1;
      for (int j = 0; j <= i; j++) {
        dp[next][j] = min(dp[next][j], dp[i][j] + (sum[notes[i]] - (notes[j] - 1 >= 0 ? sum[notes[j] - 1] : 0)) / f);
        dp[next][i] = min(dp[next][i], dp[i][j] + (sum[notes[j]] - (notes[i] - 1 >= 0 ? sum[notes[i] - 1] : 0)) / f);
      }
    }
    ll res = INF;
    for (int i = 0; i < n; i++) {
      res = min(res, dp[n - 1][i] + (sum[m - 1] - (notes[i] - 1 >= 0 ? sum[notes[i] - 1] : 0)) / f);
    }
    cout << res << "\n";
  }
  return 0;
}