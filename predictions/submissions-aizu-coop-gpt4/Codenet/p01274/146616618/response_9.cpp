#include <bits/stdc++.h>
#define INF 1e9
#define N 100000
using namespace std;
typedef long long ll;

int main() {
  int n, m, hp[101], cost[2][101], dam[2][101];
  while (cin >> n, n) {
    for (int i = 0; i < n; i++)
      cin >> hp[i];
    cin >> m;
    for (int i = 0; i < m; i++) {
      string name;
      bool type;
      cin >> name >> cost[type] >> type >> dam[type];
    }
    int dp[2][N + 10] = {};
    for (int i = 0; i < 2; i++)
      for (int j = 1; j < N + 10; j++)
        dp[i][j] = INF;
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < m; i++) {
        int end = min(N, (N / dam[k] + 1) * dam[k]);
        for (int j = dam[k]; j <= end; j++) {
          dp[k][j] = min(dp[k][j], dp[k][j - dam[k]] + cost[k]);
        }
      }
    for (int i = 0; i < 2; i++)
      for (int j = N; j >= 0; j--) {
        if (dp[i][j] < dp[i][j + 1])
          break;
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
      }
    ll ans = INF;
    for (int i = 0; i <= N; i++) {
      ll cost = dp[1][i];
      for (int j = 0; j < n; j++)
        cost += dp[0][max(0, hp[j] - i)];
      ans = min(ans, cost);
    }
    cout << ans << endl;
  }
  return 0;
}