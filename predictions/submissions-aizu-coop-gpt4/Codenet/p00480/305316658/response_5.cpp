#include <stdio.h>
long long dp[110][21]; // Automatically initialized to zero

int main() {
    int N;
    scanf("%d", &N); // Faster I/O
    int a[101];

    for (int i = 1; i <= N; i++) {
        scanf("%d", &a[i]); // Faster I/O
    }
    
    dp[1][a[1]] = 1;
    
    for (int i = 2; i < N; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j - a[i] >= 0)
                dp[i][j] += dp[i - 1][j - a[i]];
            if (j + a[i] <= 20)
                dp[i][j] += dp[i - 1][j + a[i]];
        }
    }
    printf("%lld\n", dp[N - 1][a[N]]); // Faster I/O
    return 0;
}