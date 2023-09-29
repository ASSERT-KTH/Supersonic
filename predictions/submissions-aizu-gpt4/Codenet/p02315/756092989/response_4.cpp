#include <iostream>
#include <algorithm>

const int MAX_N = 110;
const int MAX_W = 10010;

int weight[MAX_N], value[MAX_N];
int dp[MAX_W];

int main() {
    int n, W;
    std::cin >> n >> W;

    for (int i = 0; i < n; ++i) {
        std::cin >> value[i] >> weight[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int w = W; w >= weight[i]; --w) {
            dp[w] = std::max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    std::cout << dp[W] << std::endl;
    return 0;
}