#include <iostream>

constexpr int SIZE = 55;
constexpr int MOD = 100000;

int dp[SIZE][SIZE * SIZE];

int main() {
  int N, M, S;
  while (std::cin >> N >> M >> S && (N || M || S)) {
    std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), 0);
    dp[0][0] = 1;
    for (int add = 1; add <= M; ++add) {
      for (int currIndex = N * N; currIndex >= 1; --currIndex) {
        for (int currSum = add; currSum <= S; ++currSum) {
          dp[currIndex][currSum] = (dp[currIndex][currSum] + dp[currIndex - 1][currSum - add]) % MOD;
        }
      }
    }
    std::cout << dp[N * N][S] << std::endl;
  }
  return 0;
}