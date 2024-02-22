#include <iostream>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp[2][2501][2];

  cin >> n;

  int s = 1, t = 0;
  dp[s][1][0] = 0;
  dp[s][0][1] = 0;

  for (int i = 2; i <= n; i++) {
    cin >> c;
    swap(s, t);
    for (int j = 1; j <= n / 2; j++) {
      int prev0 = dp[t][j - 1][0];
      int prev1 = dp[t][j - 1][1];
      dp[s][j][0] = min(prev0, prev1 + c);
      dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
    }
  }

  cout << min(dp[s][n / 2][0], dp[s][n / 2][1]) << endl;
  return 0;
}