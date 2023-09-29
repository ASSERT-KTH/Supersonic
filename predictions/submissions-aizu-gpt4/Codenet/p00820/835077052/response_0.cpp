#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN = 1000000;
const int MAXK = 5;
int dp[MAXN][MAXK];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int sqrtn = static_cast<int>(sqrt(n));
    for (int i = 1; i <= sqrtn; i++) {
      for (int k = 1; k < MAXK; k++) {
        int mul = i * i;
        for (int j = mul; j <= n; j++) {
          dp[j][k] += dp[j - mul][k - 1];
        }
      }
    }
    printf("%d\n", dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4]);
  }
}