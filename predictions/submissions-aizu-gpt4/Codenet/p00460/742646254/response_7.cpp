#include <iostream>
#include <vector>

int main() {
  const int MOD = 100000;
  std::vector<std::vector<int>> dp(55, std::vector<int>(3030));

  int N, M, S;
  while (std::cin >> N >> M >> S && (N || M || S)) {
    for (auto &row : dp)
      std::fill(row.begin(), row.end(), 0);
    dp[0][0] = 1;

    for (int add = 1; add <= M; ++add) {
      for (int currIndex = N * N; currIndex >= 1; --currIndex) {
        for (int currSum = add; currSum <= S; ++currSum) {
          dp[currIndex][currSum] = (dp[currIndex][currSum] + dp[currIndex - 1][currSum - add]) % MOD;
        }
      }
    }
    std::cout << dp[N * N][S] << '\n';
  }

  return 0;
}