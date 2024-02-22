#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 1e9
#define N 100000

using namespace std;

struct Spell {
  int damage;
  int cost;
};

int main() {
  int n, m, hp[101];
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &hp[i]);
    vector<Spell> mg[2];
    scanf("%d", &m);
    for (int i = 0, cost, dam; i < m; i++) {
      char name[101], type[5];
      scanf("%s %d %s %d", name, &cost, type, &dam);
      if (dam)
        mg[type[0] == 'A'].push_back({dam, cost});
    }
    vector<int> dp[2];
    dp[0].resize(N + 10, INF);
    dp[1].resize(N + 10, INF);
    for (int k = 0; k < 2; k++)
      for (int i = 0; i < mg[k].size(); i++)
        for (int j = mg[k][i].damage; j <= min((N / mg[k][i].damage + 1) * mg[k][i].damage, N); j++)
          dp[k][j] = min(dp[k][j], dp[k][j - mg[k][i].damage] + mg[k][i].cost);
    for (int i = 0; i < 2; i++)
      for (int j = N; j >= 0; j--)
        dp[i][j] = min(dp[i][j], dp[i][j + 1]);
    long long ans = INF;
    for (int i = 0; i <= N; i++) {
      long long cost = dp[1][i];
      for (int j = 0; j < n; j++)
        cost += dp[0][max(0, hp[j] - i)];
      ans = min(ans, cost);
    }
    printf("%lld\n", ans);
  }
  return 0;
}