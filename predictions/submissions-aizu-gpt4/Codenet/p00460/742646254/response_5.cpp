#include <iostream>
typedef long long ll;

int main() {
  const int MOD = 100000;
  const int MAX_N = 55;
  const int MAX_S = 3030;
  int dp[MAX_N][MAX_S] = {0};
  int N, M, S;
  while (std::cin >> N >> M >> S && (N || M || S)) {
    for(int i = 0; i < MAX_N; i++)
        for(int j = 0; j < MAX_S; j++)
            dp[i][j] = 0;
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