#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 100000;

int dp[55][3030];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

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
        for (int currSum = S; currSum >= add; currSum--) {
          dp[currIndex][currSum] = (dp[currIndex][currSum] + dp[currIndex - 1][currSum - add]) % MOD;
        }
      }
    }

    cout << dp[N * N][S] << endl;
  }

  return 0;
}