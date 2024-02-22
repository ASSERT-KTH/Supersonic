#include <iostream>
#include <cstring>
using namespace std;
int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp[2][5000 + 2][2];
  memset(dp, INF, sizeof(dp));
  dp[1][1][0] = 0;
  dp[1][0][1] = 0;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    cin >> c;
    for (int j = 0; j <= n / 2; j++) {
      if (j == 0)
        dp[s][j][0] = INF;
      else
        dp[s][j][0] = min(dp[t][j - 1][0], dp[t][j - 1][1] + c);
      dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
    }
  }
  cout << min(dp[0][n / 2][0], dp[0][n / 2][1]) << endl;
}