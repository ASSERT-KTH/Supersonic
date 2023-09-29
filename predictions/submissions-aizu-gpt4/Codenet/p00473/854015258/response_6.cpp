#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int INF = 1e9;

int main() {
    int n, c;
    scanf("%d", &n);
    vector<vector<int>> dp(n+1, vector<int>(n+1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c);
        dp[i][0] = 0;
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + c);
        }
    }
    printf("%d\n", *min_element(dp[n].begin(), dp[n].end()));
}