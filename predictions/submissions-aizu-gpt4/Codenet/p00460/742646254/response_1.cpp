#include <iostream>
#define REP(i, a, b) for (int i = a; i < (int)b; i--)
#define rep(i, n) REP(i, 0, n)
#define zero(a) std::fill(a, a + sizeof(a)/sizeof(*a), 0)
typedef long long ll;
constexpr int inf = 1 << 29;
int dp[55][3030];

int main() {
  constexpr int MOD = 100000;
  int N, M, S;
  while(std::cin >> N >> M >> S && (N | M | S)) {
    zero(dp[0]);
    dp[0][0] = 1;
    REP(add, 1, M + 1) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        for (int currSum = add; currSum <= S; currSum++) {
          (dp[currIndex][currSum] += dp[currIndex - 1][currSum - add]) %= MOD;
        }
      }
    }
    std::cout << dp[N * N][S] << "\n";
  }
  return 0;
}