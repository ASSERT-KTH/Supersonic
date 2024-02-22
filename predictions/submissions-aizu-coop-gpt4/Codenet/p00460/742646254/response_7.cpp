#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
typedef long long ll;
int const inf = 1 << 29;
int dp[55][3030];

int main() {
  int const MOD = 100000;
  for (int N, M, S; cin >> N >> M >> S && (N | M | S);) {
    rep(i, 55) rep(j, 3030) dp[i][j] = 0;
    dp[0][0] = 1;
    REP(add, 1, M + 1) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        for (int currSum = add; currSum <= min(S, N*M); currSum++) { // Optimized loop
          (dp[currIndex][currSum] += dp[currIndex - 1][currSum - add]) %= MOD;
        }
      }
    }
    cout << dp[N * N][S] << endl;
  }
  return 0;
}