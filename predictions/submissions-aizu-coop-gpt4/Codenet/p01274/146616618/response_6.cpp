#include <cstdio>
#define INF 1e9
#define N 100000
typedef pair<int, int> P;
typedef long long ll;

int main() {
  int n, m, hp[101];
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &hp[i]);
    P mg[2][100000];
    int mg_size[2] = {0, 0};
    scanf("%d", &m);
    for (int i = 0, cost, dam; i < m; i++) {
      char name[10], type[10];
      scanf("%s %d %s %d", name, &cost, type, &dam);
      if (dam)
        mg[type[0] == 'A'][mg_size[type[0] == 'A']++] = P(dam, cost);
    }
    int dp[2][N + 10] = {};
    for (int i = 0; i < 2; i++)
      for (int j = 1; j < N + 10; j++)
        dp[i][j] = INF;
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < mg_size[k]; i++)
        for (int j = mg[k][i].first; j <= (N / mg[k][i].first + 1) * mg[k][i].first; j++) {
          int minN = min(N, j);
          dp[k][minN] = min(dp[k][minN], dp[k][j - mg[k][i].first] + mg[k][i].second);
        }
    for (int i = 0; i < 2; i++)
      for (int j = N; j >= 0; j--) {
        int minN = min(N, j + 1);
        dp[i][j] = min(dp[i][j], dp[i][minN]);
      }
    ll ans = INF;
    for (int i = 0; i <= N; i++) {
      ll cost = dp[1][i];
      for (int j = 0; j < n; j++)
        cost += dp[0][max(0, hp[j] - i)];
      ans = min(ans, cost);
    }
    printf("%lld\n", ans);
  }
  return 0;
}