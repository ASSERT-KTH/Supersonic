#include <iostream>
#include <algorithm> // for std::fill
using namespace std;
int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp[2][5000 + 2][2];

  // Use std::fill to initialize the array
  fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp)/sizeof(dp[0][0][0]), INF);

  dp[1][1][0] = 0;
  dp[1][0][1] = 0;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    scanf("%d", &c);
    for (int j = 0; j <= n / 2; j++) {
      int t_j_0 = dp[t][j][0], t_j_1 = dp[t][j][1];
      if (j == 0)
        dp[s][j][0] = INF;
      else
        dp[s][j][0] = min(t_j_0, dp[t][j - 1][1] + c);
      dp[s][j][1] = min(t_j_0 + c, t_j_1);
    }
  }
  printf("%d\n", min(dp[0][n / 2][0], dp[0][n / 2][1]));
}