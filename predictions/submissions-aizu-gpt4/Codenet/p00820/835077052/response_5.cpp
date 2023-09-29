#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
static const double EPS = 1e-8;
int dp[1000000][5];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i * i <= n; i++) {
      for (int j = i * i; j <= n; j++) {
        for (int k = 4; k >= 1; --k) {
          dp[j][k] += dp[j - i * i][k - 1];
        }
      }
    }
    printf("%d\n", dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1]);
  }
}