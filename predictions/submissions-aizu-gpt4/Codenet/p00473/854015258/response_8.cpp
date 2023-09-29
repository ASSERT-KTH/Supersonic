#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp[5000 + 2][2];
  for (int i = 0; i < 5002; i++) {
    dp[i][0] = INF;
    dp[i][1] = INF;
  }
  dp[1][0] = 0;
  dp[0][1] = 0;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> c;
    for (int j = 0; j <= i / 2; j++) {
      if (j == 0)
        dp[j][0] = INF;
      else
        dp[j][0] = min(dp[j - 1][0], dp[j - 1][1] + c);
      dp[j][1] = min(dp[j][0] + c, dp[j][1]);
    }
    copy(&dp[0], &dp[0] + (i/2 + 1)*2, &dp[0]);
  }
  cout << min(dp[n / 2][0], dp[n / 2][1]) << endl;
}