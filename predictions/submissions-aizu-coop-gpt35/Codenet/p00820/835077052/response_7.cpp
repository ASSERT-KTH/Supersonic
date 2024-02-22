#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    int dp[1000000];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i * i <= n; i++) {
      for (int j = i * i; j <= n; j++) {
        dp[j] += dp[j - i * i];
      }
    }
    printf("%d\n", dp[n] + dp[n - 1] + dp[n - 2] + dp[n - 3]);
  }
}