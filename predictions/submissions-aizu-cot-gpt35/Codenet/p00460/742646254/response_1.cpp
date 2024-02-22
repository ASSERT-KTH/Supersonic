#include <iostream>
using namespace std;

typedef long long ll;

int dp[55][3030];

int main() {
  int const MOD = 100000;
  int N, M, S;
  while (cin >> N >> M >> S && (N | M | S)) {
    dp[0][0] = 1;
    for (int add = 1; add <= M; add++) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        for (int currSum = add; currSum <= S; currSum++) {
          dp[currIndex][currSum] += dp[currIndex - 1][currSum - add];
        }
      }
    }
    cout << dp[N * N][S] % MOD << endl;
  }
  return 0;
}