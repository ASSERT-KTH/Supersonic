#include <bits/stdc++.h>
#define INF 1e9
#define N 100000
using namespace std;
typedef long long ll;
struct Magic {
  int dam[N];
  int cost[N];
};
int main() {
  int n, m, hp[101];
  while (cin >> n, n) {
    int max_hp = 0;
    for (int i = 0; i < n; i++) {
      cin >> hp[i];
      max_hp = max(max_hp, hp[i]);
    }
    Magic mg[2];
    cin >> m;
    for (int i = 0, cost, dam; i < m; i++) {
      string name, type;
      cin >> name >> cost >> type >> dam;
      if (dam)
        mg[type == "All"].dam[i] = dam, mg[type == "All"].cost[i] = cost;
    }
    int dp[2][N + 10] = {};
    for (int i = 0; i < 2; i++)
      for (int j = 1; j < N + 10; j++)
        dp[i][j] = INF;
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < m; i++)
        for (int j = mg[k].dam[i]; j <= min(N, (N / mg[k].dam[i] + 1) * mg[k].dam[i]); j++)
          dp[k][j] = min(dp[k][j], dp[k][j - mg[k].dam[i]] + mg[k].cost[i]);
    int dp_min[2][N + 10] = {};
    for (int i = 0; i < 2; i++)
      for (int j = N; j >= 0; j--)
        dp_min[i][j] = min(dp[i][j], dp_min[i][j + 1]);
    ll ans = INF;
    for (int i = 0; i <= max_hp; i++) {
      ll cost = dp_min[1][i];
      for (int j = 0; j < n; j++)
        cost += dp_min[0][max(0, hp[j] - i)];
      ans = min(ans, cost);
    }
    cout << ans << endl;
  }
  return 0;
}