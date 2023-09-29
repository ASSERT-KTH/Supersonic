#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const inf = 1 << 29;
int dp[55][3030];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int const MOD = 100000;
  while(true) {
    int N, M, S;
    cin >> N >> M >> S;
    if(N == 0 && M == 0 && S == 0) break;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int add = 1; add <= M; add++) {
      for (int currIndex = N * N; currIndex >= 1; currIndex--) {
        for (int currSum = add; currSum <= S; currSum++) {
          dp[currIndex][currSum] = (dp[currIndex][currSum] + dp[currIndex - 1][currSum - add]) % MOD;
        }
      }
    }
    cout << dp[N * N][S] << endl;
  }
  return 0;
}