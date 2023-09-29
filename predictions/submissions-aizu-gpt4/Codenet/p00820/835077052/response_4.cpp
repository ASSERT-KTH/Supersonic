#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int max_n = 1000000;
const int max_k = 5;
int dp[max_n][max_k];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i * i <= n; i++) {
      for (int k = 1; k < max_k; k++) {
        for (int j = i * i; j <= n; j++) {
          dp[j][k] += dp[j - i * i][k - 1];
        }
      }
    }
    printf("%d\n", dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1]);
  }
}