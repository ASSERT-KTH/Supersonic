#include <iostream>
#include <algorithm>

constexpr int INF = 100000000;

int main() {
    std::ios_base::sync_with_stdio(false);

    int n, m;
    while (std::cin >> n >> m, n) {
        int b[m];
        int a[n + 1];
        for (int i = 0; i < m; i++)
            std::cin >> b[i];
        for (int i = 1; i <= n; i++)
            std::cin >> a[i];

        short dp[20001][256];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 256; j++)
                dp[i][j] = INF;
        
        dp[0][128] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 256; j++) {
                if (dp[i][j] != INF) {
                    int p = j + b[0];
                    if (p > 255)
                        p = 255;
                    else if (p < 0)
                        p = 0;
                    int diff = a[i + 1] - p;
                    dp[i + 1][p] = std::min(dp[i + 1][p], dp[i][j] + diff * diff);
                }
            }
        }
        
        int p = 100000000;
        for (int i = 0; i < 256; i++) {
            if (dp[n][i] != INF)
                p = std::min(p, dp[n][i]);
        }
        
        std::cout << p - 1 << '\n';
    }

    return 0;
}