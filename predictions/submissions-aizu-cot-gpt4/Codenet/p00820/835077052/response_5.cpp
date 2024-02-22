#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int dp[1000000][5];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i * i <= n; i++) {
      int square = i * i;
      for (int k = 1; k <= 4; k++) {
        for (int j = square; j <= n; j++) {
          dp[j][k] += dp[j - square][k - 1];
        }
      }
    }
    printf("%d\n", dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1]);
  }
}