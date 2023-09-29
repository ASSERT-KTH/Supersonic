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
    for (int i = 0; i < n; ++i)
      scanf("%d", &hp[i]);
    vector<P> mg[2];
    scanf("%d", &m);
    for (int i = 0, cost, dam; i < m; ++i) {
      char name[101], type[4];
      scanf("%s %d %s %d", name, &cost, type, &dam);
      if (dam)
        mg[type[0] == 'A'].push_back(P(dam, cost));
    }
    int dp[2][N + 10] = {};
    memset(dp, 0x3f, sizeof(dp));
    for (int k = 0; k < 2; ++k)
      for (int i = 0; i < mg[k].size(); ++i)
        for (int j = mg[k][i].f; j <= (N / mg[k][i].f + 1) * mg[k][i].f; ++j)
          dp[k][min(N, j)] =
              min(dp[k][min(N, j)], dp[k][j - mg[k][i].f] + mg[k][i].s);
    for (int i = 0; i < 2; ++i)
      for (int j = N; j >= 0; --j)
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
    ll ans = INF;
    for (int i = 0; i <= N; ++i) {
      ll cost = dp[1][i];
      for (int j = 0; j < n; ++j)
        cost += dp[0][max(0, hp[j] - i)];
      ans = min(ans, cost);
    }
    printf("%lld\n", ans);
  }
  return 0;
}