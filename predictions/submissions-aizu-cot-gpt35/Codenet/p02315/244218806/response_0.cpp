#include <iostream>
#include <vector>

int dp[10001];

int main() {
    int N, W;
    std::cin >> N >> W;
    int v[N], w[N];
    for (int i = 0; i < N; i++)
        std::cin >> v[i] >> w[i];
    for (int i = 0; i < N; i++) {
        for (int j = W; j >= w[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    std::cout << dp[W] << std::endl;
    return 0;
}