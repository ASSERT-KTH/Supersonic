#include <iostream>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  const int INF = 1000000000;
  int n, c;
  static int dp[2][5002][2];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 5002; j++) {
      dp[i][j][0] = INF;
      dp[i][j][1] = INF;
    }
  dp[1][1][0] = 0;
  dp[1][0][1] = 0;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    cin >> c;
    for (int j = 0; j <= n / 2; j++) {
      int t_j_0 = dp[t][j][0], t_j_1 = dp[t][j][1], t_jm1_0 = dp[t][j - 1][0], t_jm1_1 = dp[t][j - 1][1];
      if (j == 0)
        dp[s][j][0] = INF;
      else
        dp[s][j][0] = min(t_jm1_0, t_jm1_1 + c);
      int t_j_0_c = t_j_0 + c;
      dp[s][j][1] = min(t_j_0_c, t_j_1);
    }
  }
  cout << min(dp[0][n / 2][0], dp[0][n / 2][1]) << "\n";
}