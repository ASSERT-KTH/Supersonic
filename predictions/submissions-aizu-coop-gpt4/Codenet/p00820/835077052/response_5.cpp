#define _USE_MATH_DEFINES
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
int tx[] = {0, 1, 0, -1};
int ty[] = {-1, 0, 1, 0};
static const double EPS = 1e-8;
int dp[1000001][5];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    memset(dp, 0, sizeof(int)*(n+1)*5); // Optimized memset
    dp[0][0] = 1;
    for (int i = 1; i * i <= n; i++) {
      for (int k = 1; k <= 4; k++) {
        for (int j = n; j >= i * i; j--) { // Optimized loop
          dp[j][k] += dp[j - i * i][k - 1];
        }
      }
    }
    printf("%d\n", dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1]);
  }
}