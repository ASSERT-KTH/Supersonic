#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int const MOD = 100000;
  for (int N, M, S; cin >> N >> M >> S && (N | M | S);) {
    vector<vector<int>> dp(N * N + 1, vector<int>(S + 1, 0));
    dp[0][0] = 1;
    for (int add = 1; add <= M; add++) {
      for (int currIndex = 1; currIndex <= N * N; currIndex++) {
        for (int currSum = S; currSum >= add; currSum--) {
          dp[currIndex][currSum] += dp[currIndex - 1][currSum - add];
        }
        dp[currIndex][currSum] %= MOD;
      }
    }
    cout << dp[N * N][S] << endl;
  }
  return 0;
}