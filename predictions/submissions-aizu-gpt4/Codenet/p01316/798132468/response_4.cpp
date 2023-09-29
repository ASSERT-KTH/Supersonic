#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define r(i, n) for (int i = 0; i < n; i++)
#define INF INT_MAX
#define MAX 256

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m, n) {
        std::vector<int> b(m);
        std::vector<int> a(n + 1);
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(MAX, INF));
        r(i, m) std::cin >> b[i];
        r(i, n) std::cin >> a[i + 1];
        dp[0][128] = 0;
        r(i, n) r(j, MAX) if (dp[i][j] != INF) r(k, m) {
            int p = std::clamp(j + b[k], 0, 255);
            dp[i + 1][p] = std::min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
        }
        int p = *std::min_element(dp[n].begin(), dp[n].end());
        std::cout << p << '\n';
    }
    return 0;
}