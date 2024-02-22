#include <iostream>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp[5000 + 2][2];
  dp[1][0] = 0;
  dp[0][1] = 0;

  cin >> n;

  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    cin >> c;
    dp[0][0] = INF;
    for (int j = 1; j <= n / 2; j++) {
      dp[j][0] = min(dp[j - 1][0], dp[j - 1][1] + c);
      dp[j][1] = min(dp[j][0] + c, dp[j][1]);
    }
  }

  cout << min(dp[n / 2][0], dp[n / 2][1]) << "\n";

  return 0;
}