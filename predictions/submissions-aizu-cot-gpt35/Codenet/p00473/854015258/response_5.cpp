#include <iostream>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;
  scanf("%d", &n);

  int **dp = new int*[2];
  for (int i = 0; i < 2; i++) {
    dp[i] = new int[n / 2 + 1];
  }

  dp[1][0] = 0;

  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    scanf("%d", &c);
    for (int j = 1; j <= n / 2; j++) {
      dp[s][j] = min(dp[t][j - 1] + c, dp[t][j]);
    }
  }

  printf("%d\n", min(dp[0][n / 2], dp[1][n / 2]));

  for (int i = 0; i < 2; i++) {
    delete[] dp[i];
  }
  delete[] dp;

  return 0;
}