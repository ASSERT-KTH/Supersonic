#include <iostream>
#include <algorithm>
#include <cstring>

const int MAX_N = 20001;
const int MAX_M = 256;
const int INF = 100000000;

int dp[MAX_N][MAX_M];

int main() {
    int n, m;
    while (std::cin >> n >> m && n) {
        int b[MAX_M];
        int a[MAX_N];
        for (int i = 0; i < m; i++) {
            std::cin >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }
        std::memset(dp, INF, sizeof(dp));
        dp[0][128] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < MAX_M; j++) {
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
        int p = INF;
        for (int i = 0; i < MAX_M; i++) {
            if (dp[n][i] != INF) {
                p = std::min(p, dp[n][i]);
            }
        }
        std::cout << p - 1 << std::endl;
    }
    return 0;
}