#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 100000;
const int MAX_N = 2600;
const int MAX_M = 55;
int dp[MAX_N][MAX_M];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, S;
  while (cin >> N >> M >> S && (N | M | S)) {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= M; ++i) {
      for (int j = N * N; j >= i; --j) {
        for (int k = S; k >= i; --k) {
          dp[j][i] += dp[j - i][i - 1];
          dp[j][i] %= MOD;
        }
      }
    }
    cout << dp[N * N][M] << "\n";
  }
  return 0;
}