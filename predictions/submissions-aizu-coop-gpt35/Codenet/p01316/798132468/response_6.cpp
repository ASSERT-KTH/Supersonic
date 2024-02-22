#include <iostream>

#define INF 100000000

int dp[20001][256];

int main() {
    std::ios_base::sync_with_stdio(false);

    int n, m;
    while (std::scanf("%d %d", &n, &m), n) {
        int b[m];
        int a[n + 1];
        for (int i = 0; i < m; i++) {
            std::scanf("%d", &b[i]);
        }
        for (int i = 1; i <= n; i++) {
            std::scanf("%d", &a[i]);
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 256; j++) {
                dp[i][j] = INF;
            }
        }

        dp[0][128] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 256; j++) {
                if (dp[i][j] != INF) {
                    for (int k = 0; k < m; k++) {
                        int p = j + b[k];
                        if (p > 255) {
                            p = 255;
                        }
                        if (p < 0) {
                            p = 0;
                        }
                        dp[i + 1][p] = std::min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
                    }
                }
            }
        }

        int p = 100000000;
        for (int i = 0; i < 256; i++) {
            if (dp[n][i] != INF) {
                p = std::min(p, dp[n][i]);
            }
        }

        std::printf("%d\n", p - 1);
    }

    return 0;
}