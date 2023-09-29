#include <iostream>
#include <algorithm>

int main() {
    const int MAX_N = 110, MAX_W = 10010;
    int n, W;
    int weight[MAX_N], value[MAX_N];
    int dp[MAX_N][MAX_W] = {0};

    std::cin >> n >> W;
    for (int i = 0; i < n; i++) {
        std::cin >> value[i] >> weight[i];
    }

    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            if (w >= weight[i]) {
                dp[i + 1][w] = std::max(dp[i][w - weight[i]] + value[i], dp[i][w]);
            } else {
                dp[i + 1][w] = dp[i][w];
            }
        }
    }
    std::cout << dp[n][W] << std::endl;

    return 0;
}