#include <stdio.h>

int main() {
    int n, m = 5000, i, j, min;
    scanf("%d", &n);
    
    int coins[n+1];
    for (i = 1; i <= n; i++) {
        scanf("%d", &coins[i]);
    }
    
    int dp[m+1];
    dp[0] = 0;
    for (i = 1; i <= m; i++) {
        dp[i] = m;
    }
    
    for (i = 1; i <= n; i++) {
        for (j = coins[i]; j <= m; j++) {
            min = dp[j - coins[i]] + 1;
            if (min < dp[j]) {
                dp[j] = min;
            }
        }
    }
    
    printf("%d\n", dp[m]);
    
    return 0;
}