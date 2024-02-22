#include <iostream>
#include <algorithm>
#include <omp.h>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;

  static int dp[5000 + 2][2];
  #pragma omp parallel for
  for (int j = 0; j < 5002; j++) {
    dp[j][0] = INF;
    dp[j][1] = INF;
  }
  dp[1][0] = 0;
  dp[0][1] = 0;
  scanf("%d", &n);
  int half_n = n / 2;
  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    scanf("%d", &c);
    for (int j = 0; j <= half_n; j++) {
      if (j == 0)
        dp[j][0] = INF;
      else
        dp[j][0] = min(dp[j - 1][t], dp[j - 1][1] + c);
      int min_val = min(dp[j][t] + c, dp[j][1]);
      dp[j][1] = min_val;
    }
  }
  printf("%d\n", min(dp[half_n][0], dp[half_n][1]));
}