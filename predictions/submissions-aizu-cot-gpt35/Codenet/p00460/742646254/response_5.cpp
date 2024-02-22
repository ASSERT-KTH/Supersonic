#include <iostream>
#include <vector>

typedef long long ll;

int main() {
  int const MOD = 100000;
  for (int N, M, S; std::cin >> N >> M >> S && (N | M | S);) {
    std::vector<std::vector<int>> dp(N * N + 1, std::vector<int>(S + 1));
    dp[0][0] = 1;
    for (int add = 1; add <= M; add++) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        for (int currSum = add; currSum <= S; currSum++) {
          dp[currIndex][currSum] += dp[currIndex - 1][currSum - add];
          dp[currIndex][currSum] %= MOD;
        }
      }
    }
    std::cout << dp[N * N][S] << std::endl;
  }
  return 0;
}