#include <cstdio>
#define MAX 4001
#define MOD 1000000007
int dp[MAX][4] = {0};
int prefixSum[MAX][4] = {0};

int main() {
  for (int i = 0; i < MAX; i++)
    dp[i][0] = i <= 1000 ? 1 : 0;
  for (int i = 1; i < 4; i++) {
    for (int j = 0; j < MAX; j++) {
      dp[j][i] = prefixSum[j][i - 1];
      if (j > 1000)
        dp[j][i] -= prefixSum[j - 1001][i - 1];
      dp[j][i] %= MOD;
      prefixSum[j][i] = (j > 0 ? prefixSum[j - 1][i] : 0) + dp[j][i];
      prefixSum[j][i] %= MOD;
    }
  }
  int n;
  while (scanf("%d", &n) != EOF)
    printf("%d\n", dp[n][3]);
  return 0;
}