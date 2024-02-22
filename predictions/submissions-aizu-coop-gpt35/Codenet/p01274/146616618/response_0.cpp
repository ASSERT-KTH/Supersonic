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

    unordered_set<int> mgAll;
    unordered_multiset<int> mgSingle;
    
    scanf("%d", &m);
    for (int i = 0, cost, dam; i < m; i++) {
      char name[10], type[10];
      scanf("%s %d %s %d", name, &cost, type, &dam);
      if (dam) {
        if (strcmp(type, "All") == 0)
          mgAll.insert(dam);
        else
          mgSingle.insert(dam);
      }
    }
    
    int dp[2][N + 10] = {};
    for (int j = 1; j < N + 10; j++) {
      dp[0][j] = INF;
      dp[1][j] = INF;
    }

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < N + 10; j++) {
        if (i == 0 && j > 0)
          dp[0][j] = min(dp[0][j], dp[0][j - 1]);
        if (i == 1 && j < N)
          dp[1][j] = min(dp[1][j], dp[1][j + 1]);
      }
    }

    for (auto& dam : mgAll) {
      for (int j = dam; j <= (N / dam + 1) * dam; j++) {
        dp[0][min(N, j)] = min(dp[0][min(N, j)], dp[0][j - dam]);
        dp[1][min(N, j)] = min(dp[1][min(N, j)], dp[1][j - dam]);
      }
    }

    for (auto& dam : mgSingle) {
      for (int j = dam; j <= (N / dam + 1) * dam; j++)
        dp[1][min(N, j)] = min(dp[1][min(N, j)], dp[1][j - dam]);
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