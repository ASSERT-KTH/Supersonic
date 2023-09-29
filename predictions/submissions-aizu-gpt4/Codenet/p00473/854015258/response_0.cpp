#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    const int INF = 1000000000;
    int n;
    scanf("%d", &n);
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n/2 + 1, vector<int>(2, INF)));
    dp[1][1][0] = dp[1][0][1] = 0;
    for (int i = 2; i <= n; i++) {
        int s = i % 2, t = 1 - s;
        int c;
        scanf("%d", &c);
        for (int j = 0; j <= i/2; j++) {
            if (j != 0) dp[s][j][0] = min(dp[t][j - 1][0], dp[t][j - 1][1] + c);
            if (j != i) dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
        }
    }
    printf("%d\n", min(dp[n % 2][n / 2][0], dp[n % 2][n / 2][1]));
    return 0;
}