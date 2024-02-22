#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;
  vector<vector<vector<int>>> dp(2, vector<vector<int>>(5000 + 2, vector<int>(2, INF)));

  dp[1][1][0] = 0;
  dp[1][0][1] = 0;

  scanf("%d", &n);

  for (int i = 2; i <= n; i++) {
    int s = i % 2;
    int t = 1 - s;
    scanf("%d", &c);

    dp[s][0][0] = INF;

    for (int j = 1; j <= n / 2; j++) {
      dp[s][j][0] = min(dp[t][j - 1][0], dp[t][j - 1][1] + c);
      dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
    }
  }

  printf("%d\n", min(dp[0][n / 2][0], dp[0][n / 2][1]));
}