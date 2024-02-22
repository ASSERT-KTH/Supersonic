#include <iostream>
using namespace std;
int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp[2][5002][2]; // Reduced size of dp array
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 5002; j++) {
      dp[i][j][0] = INF;
      dp[i][j][1] = INF;
    }
  dp[1][1][0] = 0;
  dp[1][0][1] = 0;
  scanf("%d", &n);
  int s, t;
  for (int i = 2; i <= n; i++) {
    s = i % 2;
    t = 1 - s; // Compute s and t outside the loop
    scanf("%d", &c);
    for (int j = 0; j <= n / 2; j++) {
      if (j == 0)
        dp[s][j][0] = INF;
      else
        dp[s][j][0] = min(dp[t][j - 1][0], dp[t][j - 1][1] + c);
      dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
    }
  }
  printf("%d\n", min(dp[0][n / 2][0], dp[0][n / 2][1]));
}