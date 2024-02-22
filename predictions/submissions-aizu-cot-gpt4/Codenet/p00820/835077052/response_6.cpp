#include <cstdio>
#include <cstring>
using namespace std;

static const int MAX_N = 100000;
int dp[MAX_N][5];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n == 0)
            break;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i * i <= n; i++) {
            int sq = i * i;
            for (int k = 1; k <= 4; k++) {
                for (int j = sq; j <= n; j++) {
                    dp[j][k] += dp[j - sq][k - 1];
                }
            }
        }
        int result = dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1];
        printf("%d\n", result);
    }
}