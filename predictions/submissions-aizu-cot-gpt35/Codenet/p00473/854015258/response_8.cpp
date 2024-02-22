#include <iostream>

int main() {
    const int INF = 1000000000;
    int n, c;
    std::cin >> n;

    int** dp = new int*[2];
    for (int i = 0; i < 2; i++) {
        dp[i] = new int[n/2 + 1];
        for (int j = 0; j <= n/2; j++) {
            dp[i][j] = INF;
        }
    }
    dp[1][1] = 0;
    dp[1][0] = 0;

    for (int i = 2; i <= n; i++) {
        int s = i % 2;
        int t = 1 - s;
        std::cin >> c;
        for (int j = 0; j <= n/2; j++) {
            dp[s][j] = dp[t][j - 1] + c;
            if (j > 0) {
                dp[s][j] = std::min(dp[s][j], dp[t][j - 1] + c);
                dp[s][j] = std::min(dp[s][j], dp[t][j]);
            }
        }
    }

    std::cout << std::min(dp[0][n/2], dp[0][n/2]) << std::endl;

    for (int i = 0; i < 2; i++) {
        delete[] dp[i];
    }
    delete[] dp;

    return 0;
}