#include <iostream>

const int MOD = 100000;
const int MAX_INDEX = 55;
const int MAX_SUM = 3030;

int dp[MAX_INDEX][MAX_SUM];

int main() {
    for (int N, M, S; std::cin >> N >> M >> S && (N | M | S);) {
        for(int i = 0; i < MAX_INDEX; ++i) {
            for(int j = 0; j < MAX_SUM; ++j) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (int add = 1; add <= M; ++add) {
            for (int currIndex = N * N; currIndex >= 1; --currIndex) {
                for (int currSum = add; currSum <= S; ++currSum) {
                    (dp[currIndex][currSum] += dp[currIndex - 1][currSum - add]) %= MOD;
                }
            }
        }
        std::cout << dp[N * N][S] << std::endl;
    }
    return 0;
}