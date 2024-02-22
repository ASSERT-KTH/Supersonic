#include <iostream>
#include <algorithm>
#include <cstdint>

constexpr int MAX_N = 20001;
constexpr int MAX_M = 256;
constexpr int INF = 100000000;

int dp[MAX_N][MAX_M];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m, n) {
        int b[MAX_M];
        int a[MAX_N];
        for (int i = 0; i < m; i++) {
            std::cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            std::cin >> a[i + 1];
        }

        for (int i = 0; i < n; i++) {
            for (uint8_t j = 0; j < MAX_M; j++) {
                dp[i][j] = INF;
            }
        }

        dp[0][128] = 1;
        for (int i = 0; i < n; i++) {
            for (uint8_t j = 0; j < MAX_M; j++) {
                if (dp[i][j] != INF) {
                    for (uint8_t k = 0; k < m; k++) {
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
        for (int i = 0; i < MAX_M; i++) {
            if (dp[n][i] != INF) {
                p = std::min(p, dp[n][i]);
            }
        }

        std::cout << p - 1 << '\n';
    }

    return 0;
}