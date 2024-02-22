#include <cstdio>
#include <cstring>

typedef long long ll;

const int MAXN = 1000000;
const int MAXK = 4;

int dp[MAXN][MAXK];

int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i * i <= n + 1; i++) {
      for (int k = 1; k <= MAXK; k++) {
        for (int j = i * i; j <= n - i * i; j++) {
          dp[j][k] += dp[j - i * i][k - 1];
        }
      }
    }
    int result = 0;
    for (int k = 1; k <= MAXK; k++) {
      result += dp[n][k];
    }
    printf("%d\n", result);
  }
  return 0;
}