#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
const int MAX_N = 5000;
int dp[2][MAX_N + 2][2];

int main() {
    int n, c;
    fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(int), INF);
    dp[1][1][0] = 0;
    dp[1][0][1] = 0;
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        int s = i & 1, t = s ^ 1;
        scanf("%d", &c);
        for (int j = 0; j <= n / 2; ++j) {
            dp[s][j][0] = (j == 0) ? INF : min(dp[t][j - 1][0], dp[t][j - 1][1] + c);
            dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
        }
    }
    printf("%d\n", min(dp[n & 1][n / 2][0], dp[n & 1][n / 2][1]));
    return 0;
}