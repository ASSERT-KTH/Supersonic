#include <iostream>
#include <cstring>

typedef long long ll;

const int MOD = 100000;
const int MAX_N = 55;
const int MAX_S = 3030;

ll dp[MAX_N][MAX_S];

int main() {
  int N, M, S;
  while (std::cin >> N >> M >> S && (N | M | S)) {
    std::memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int add = 1; add <= M; add++) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        int startSum = add;
        int endSum = S - (M - add);

        if (endSum < startSum) {
          continue;
        }

        for (int currSum = startSum; currSum <= endSum; currSum++) {
          dp[currIndex][currSum] += dp[currIndex - 1][currSum - add];
          if (dp[currIndex][currSum] >= MOD) {
            dp[currIndex][currSum] -= MOD;
          }
        }
      }
    }

    std::cout << dp[N * N][S] << std::endl;
  }

  return 0;
}