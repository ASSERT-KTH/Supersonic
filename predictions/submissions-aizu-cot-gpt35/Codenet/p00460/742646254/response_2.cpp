#include <iostream>
using namespace std;

typedef long long ll;

int const inf = 1 << 29;

int dp[55][3030];

int main() {
  int const MOD = 100000;
  int N, M, S;
  while (cin >> N >> M >> S && (N != 0 && M != 0 && S != 0)) {
    for (int i = 0; i < 55; i++) {
      for (int j = 0; j < 3030; j++) {
        dp[i][j] = 0;
      }
    }
    dp[0][0] = 1;
    for (int add = 1; add <= M; add++) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        for (int currSum = add; currSum <= S; currSum++) {
          int temp = dp[currIndex - 1][currSum - add];
          dp[currIndex][currSum] = (dp[currIndex][currSum] + temp) % MOD;
        }
      }
    }
    cout << dp[N * N][S] << endl;
  }
  return 0;
}