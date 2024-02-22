#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  const int INF = 1000000000;
  int dp[2][2] = { {INF, INF}, {INF, INF} };

  int n, c;
  scanf("%d", &n);
  dp[1][0] = 0;
  dp[1][1] = 0;

  for (int i = 2; i <= n; i++) {
    int s = i % 2;
    int t = 1 - s;
    scanf("%d", &c);

    dp[s][0] = INF;
    #pragma omp parallel for
    for (int j = 0; j <= n / 2; j++) {
      dp[s][0] = min(dp[t][j - 1][0], dp[t][j - 1][1] + c);
      dp[s][1] = min(dp[t][j][0] + c, dp[t][j][1]);
    }
  }

  printf("%d\n", min(dp[0][n / 2][0], dp[0][n / 2][1]));
  return 0;
}