#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, W;
    std::cin >> N >> W;
    std::vector<int> v(N), w(N), dp(W+1, 0);
    
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