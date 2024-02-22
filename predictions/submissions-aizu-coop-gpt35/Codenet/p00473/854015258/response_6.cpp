#include <iostream>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;
  scanf("%d", &n);

  int dp[2][n / 2 + 1][2];
  for (int i = 0; i <= n / 2; i++) {
    dp[0][i][0] = INF;
    dp[0][i][1] = INF;
    dp[1][i][0] = INF;
    dp[1][i][1] = INF;
  }

  dp[1][1][0] = 0;
  dp[1][0][1] = 0;

  for (int i = 2; i <= n; i++) {
    int s = i % 2;
    int t = 1 - s;
    scanf("%d", &c);
    for (int j = 0; j <= i / 2; j++) {
      dp[s][j][0] = (j == 0) ? INF : min(dp[t][j - 1][0], dp[t][j - 1][1] + c);
      dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
    }
  }

  printf("%d\n", min(dp[n % 2][n / 2][0], dp[n % 2][n / 2][1]));
  return 0;
}