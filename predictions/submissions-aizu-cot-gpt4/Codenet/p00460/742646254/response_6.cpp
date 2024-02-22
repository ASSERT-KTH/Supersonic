#include <iostream>
#include <cstring>

#define REP(i, a, b) for (int i = a; i < (int)b; i++)

typedef int int32;
int32 const inf = 1 << 29;
int32 dp[55][3030];

int main() {
  int32 const MOD = 100000;
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  for (int32 N, M, S; std::cin >> N >> M >> S && (N || M || S);) {
    std::memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    REP(add, 1, M + 1) {
      for (int32 currIndex = N * N; currIndex >= 1; currIndex--) {
        for (int32 currSum = add; currSum <= S; currSum++) {
          (dp[currIndex][currSum] += dp[currIndex - 1][currSum - add]) %= MOD;
        }
      }
    }
    std::cout << dp[N * N][S] << std::endl;
  }
  return 0;
}