#include <iostream>
using namespace std;

const int MOD = 100000;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int dp[55][3030];

  while (true) {
    int N, M, S;
    cin >> N >> M >> S;

    if (N == 0 && M == 0 && S == 0) {
      break;
    }

    for (int i = 0; i < 55; i++) {
      for (int j = 0; j < 3030; j++) {
        dp[i][j] = 0;
      }
    }

    dp[0][0] = 1;

    for (int add = 1; add <= M; add++) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        for (int currSum = add; currSum <= S - (M - add); currSum++) {
          dp[currIndex][currSum] = (dp[currIndex][currSum] + dp[currIndex - 1][currSum - add]) % MOD;
        }
      }
    }

    cout << dp[N * N][S] << endl;
  }

  return 0;
}