#include <bits/stdc++.h>
#define INF 1e9
#define f first
#define s second
#define N 100000
using namespace std;
typedef pair<int, int> P;
typedef long long ll;

int main() {
  int n, m, hp[101];
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &hp[i]);
    
    int mg_cost[2][N + 10] = {};
    int mg_dam[2][N + 10] = {};

    scanf("%d", &m);
    for (int i = 0, cost, dam; i < m; i++) {
      char name[100], type[100];
      scanf("%s %d %s %d", name, &cost, type, &dam);
      if (dam)
        mg_dam[type[0] == 'A'].push_back(dam);
        mg_cost[type[0] == 'A'].push_back(cost);
    }
    
    int dp[2][N + 10] = {};
    for (int i = 0; i < 2; i++)
      for (int j = 1; j < N + 10; j++)
        dp[i][j] = INF;
    
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < mg_dam[k].size(); i++) {
        int dam = mg_dam[k][i];
        int cost = mg_cost[k][i];
        for (int j = dam; j <= (N / dam + 1) * dam; j++) {
          dp[k][min(N, j)] = min(dp[k][min(N, j)], dp[k][j - dam] + cost);
        }
      }
    }
    
    for (int i = 0; i < 2; i++) {
      for (int j = N; j >= 0; j--) {
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
      }
    }

    ll ans = INF;
    for (int i = 0; i <= N; i++) {
      ll cost = dp[1][i];
      for (int j = 0; j < n; j++) {
        cost += dp[0][max(0, hp[j] - i)];
      }
      ans = min(ans, cost);
    }
    printf("%lld\n", ans);
  }
  return 0;
}