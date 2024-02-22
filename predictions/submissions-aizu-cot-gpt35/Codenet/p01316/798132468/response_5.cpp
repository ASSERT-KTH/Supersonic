#include <iostream>
#include <algorithm>
#include <limits>

const int INF = std::numeric_limits<int>::max() / 2;

int main() {
    int n, m;
    while (std::cin >> n >> m, n) {
        int b[m];
        int a[n + 1];
        for (int i = 0; i < m; i++) {
            std::cin >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
        }

        int dp[256];
        std::fill(dp, dp + 256, INF);
        dp[128] = 1;

        for (int i = 1; i <= n; i++) {
            for (int k = 0; k < m; k++) {
                int p = a[i] - b[k];
                p = std::max(p, 0);
                p = std::min(p, 255);
                dp[p] = std::min(dp[p], dp[a[i]] + (a[i] - p) * (a[i] - p));
            }
        }

        int p = INF;
        for (int i = 0; i < 256; i++) {
            if (dp[i] != INF) {
                p = std::min(p, dp[i]);
            }
        }
        std::cout << p - 1 << std::endl;
    }

    return 0;
}