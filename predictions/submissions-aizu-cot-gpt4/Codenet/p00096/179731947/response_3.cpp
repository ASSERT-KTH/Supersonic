#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
  unsigned long long dp[4001][5];
  for (int j = 0; j <= 4000; j++)
    for (int i = 0; i <= 4; i++)
      dp[j][i] = i == 1 && j <= 1000 ? 1 : 0;
  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= 4000; j++)
      for (int k = 0; k <= min(j, 1000); k++)
        dp[j][i] += dp[j - k][i - 1];
  int n;
  while(scanf("%d", &n) != EOF)
    printf("%llu\n", dp[n][4]);
  return 0;
}