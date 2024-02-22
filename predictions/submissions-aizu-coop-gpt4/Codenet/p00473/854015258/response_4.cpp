#include <iostream>
using namespace std;
int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp[5002][2];
  for (int i = 0; i < 5002; i++) {
    dp[i][0] = INF;
    dp[i][1] = INF;
  }
  dp[0][0] = 0;
  dp[1][1] = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int s = i & 1, t = 1 - s;
    scanf("%d", &c);
    dp[0][s] = INF; // Move this out of the loop
    for (int j = 1; j <= n / 2; j++) {
      dp[j][s] = min(dp[j - 1][t], dp[j - 1][s] + c);
      dp[j][t] = min(dp[j][t] + c, dp[j][s]);
    }
  }
  printf("%d\n", min(dp[n / 2][0], dp[n / 2][1]));
}