#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;
int dp[MAXN][5];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while (cin >> n) {
    if (n == 0) break;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i * i <= n; i++) {
      for (int k = 1; k <= 4; k++) {
        for (int j = i * i; j <= n; j++) {
          dp[j][k] += dp[j - i * i][k - 1];
        }
      }
    }
    cout << dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1] << "\n";
  }

  return 0;
}