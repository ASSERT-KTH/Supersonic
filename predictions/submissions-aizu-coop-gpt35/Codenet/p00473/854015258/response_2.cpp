#include <iostream>
#include <climits>
using namespace std;

int main() {
  const int INF = INT_MAX;
  int n, c;
  static int dp[2][5000 / 2 + 1][2];

  for (int i = 0; i < 2; i++)
    for (int j = 0; j <= n / 2; j++) {
      dp[i][j][0] = INF;
      dp[i][j][1] = INF;
    }

  dp[1][1][0] = 0;
  dp[1][0][1] = 0;

  cin >> n;

  for (int i = 2; i <= n; i++) {
    int s = i % 2;
    cin >> c;

    for (int j = 0; j <= n / 2; j++) {
      if (j == 0)
        dp[s][j][0] = INF;
      else
        dp[s][j][0] = min(dp[1 - s][j - 1][0], dp[1 - s][j - 1][1] + c);

      dp[s][j][1] = min(dp[1 - s][j][0] + c, dp[1 - s][j][1]);
    }
  }

  cout << min(dp[0][n / 2][0], dp[0][n / 2][1]) << endl;
}