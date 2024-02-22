#include <iostream>
using namespace std;
int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp[2][2];
  dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = INF;
  dp[1][0] = 0;
  dp[1][1] = 0;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    scanf("%d", &c);
    dp[s][0] = INF;
    for (int j = 1; j <= n / 2; j++) {
      dp[s][0] = min(dp[t][0], dp[t][1] + c);
      dp[s][1] = min(dp[t][0] + c, dp[t][1]);
    }
  }
  printf("%d\n", min(dp[0][0], dp[0][1]));
}