#include <iostream>
#include <cstring>
using namespace std;
const int INF = 1000000000;
const int maxn = 5000 + 2;
int dp[2][maxn][2];

int main() {
  memset(dp, INF, sizeof(dp)); // Initialize all elements in dp to INF

  dp[1][1][0] = 0;
  dp[1][0][1] = 0;

  int n, c;
  scanf("%d", &n);

  for (int i = 2; i <= n; i++) {
    int s = i & 1, t = s ^ 1; // Use bitwise AND and XOR operation instead of modulo operation
    scanf("%d", &c);

    // Separate the loop where j == 0 and j > 0
    dp[s][0][0] = INF;
    for (int j = 1; j <= n / 2; j++) {
      dp[s][j][0] = min(dp[t][j - 1][0], dp[t][j - 1][1] + c);
      dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
    }
  }

  printf("%d\n", min(dp[0][n / 2][0], dp[0][n / 2][1]));
  return 0;
}