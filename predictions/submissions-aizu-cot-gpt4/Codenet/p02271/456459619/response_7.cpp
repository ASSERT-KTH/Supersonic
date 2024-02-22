#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> N(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &N[i]);
    }
    int t;
    scanf("%d", &t);
    while(t--) {
        int sum;
        scanf("%d", &sum);
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1, false));
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j < N[i - 1])
                    dp[i][j] = dp[i - 1][j];
                if (j >= N[i - 1])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - N[i - 1]];
            }
        }
        if (dp[n][sum]) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}