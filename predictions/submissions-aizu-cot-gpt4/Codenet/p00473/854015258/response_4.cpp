#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
static int dp[2][5002][2];
int n, c;

int main() {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j <= 5000; j++)
      dp[i][j][0] = dp[i][j][1] = INF;

  scanf("%d", &n);
  dp[1][0][0] = dp[1][0][1] = 0;
  bool flip = true;
  for (int i = 2; i <= n; i++) {
    flip = !flip;
    scanf("%d", &c);
    for (int j = 0; j <= n / 2; j++) {
      if (j == 0)
        dp[flip][j][0] = INF;
      else
        dp[flip][j][0] = min(dp[!flip][j - 1][0], dp[!flip][j - 1][1] + c);
      dp[flip][j][1] = min(dp[!flip][j][0] + c, dp[!flip][j][1]);
    }
  }
  printf("%d\n", min(dp[flip][n / 2][0], dp[flip][n / 2][1]));
  return 0;
}