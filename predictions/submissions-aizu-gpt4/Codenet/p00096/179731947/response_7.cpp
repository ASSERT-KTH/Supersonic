#include <iostream>

int main() {
    unsigned long long dp[4001][5] = {0};

    for (int i = 0; i <= 1000; ++i) {
        dp[i][1] = 1;
    }

    for (int i = 2; i <= 4; ++i) {
        for (int j = 0; j <= 4000; ++j) {
            dp[j][i] = dp[j][i-1];
            if (j > i-1) dp[j][i] += dp[j-i][i];
        }
    }

    int n;
    while (std::cin >> n) {
        std::cout << dp[n][4] << std::endl;
    }
    return 0;
}