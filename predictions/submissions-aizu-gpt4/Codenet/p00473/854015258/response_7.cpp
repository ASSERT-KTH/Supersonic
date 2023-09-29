#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    const int INF = 1000000000;
    int n, c;
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(5002, vector<int>(2, INF)));
    dp[0][0][0] = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int s = i & 1, t = !s;
        scanf("%d", &c);
        for (int j = 0; j <= i/2; j++) {
            if(j) dp[s][j][0] = min(dp[t][j - 1][0], dp[t][j - 1][1] + c);
            if(i > j) dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
        }
    }

    printf("%d\n", min(dp[n & 1][n / 2][0], dp[n & 1][n / 2][1]));
    return 0;
}