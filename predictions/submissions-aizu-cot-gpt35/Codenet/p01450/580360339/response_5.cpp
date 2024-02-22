#include <iostream>

const int mod = 1000000007;
const int MAX_N = 201;
const int MAX_W = 10001;

int N, W;
int w[MAX_N];
int dp[2][MAX_W][MAX_N];

int main() {
    std::cin >> N >> W;
    for (int i = 0; i < N; i++) {
        std::cin >> w[i];
    }

    for (int j = 0; j <= W; j++) {
        dp[N % 2][j][N - 1] = (j >= w[N - 1]) ? 1 : 0;
    }

    for (int i = N - 2; i >= 0; i--) {
        for (int j = W; j >= 0; j--) {
            for (int k = 0; k < N - 1; k++) {
                dp[i % 2][j][k] = dp[(i + 1) % 2][j][k];
                if (j + w[i] <= W) {
                    dp[i % 2][j][k] += dp[(i + 1) % 2][j + w[i]][i];
                    dp[i % 2][j][k] %= mod;
                }
            }
        }
    }

    std::cout << dp[0][0][N - 1] << std::endl;

    return 0;
}