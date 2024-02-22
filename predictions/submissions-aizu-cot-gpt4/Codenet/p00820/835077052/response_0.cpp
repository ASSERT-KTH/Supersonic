#include <vector>
#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;

int main() {
  vector<vector<ll>> dp(1000000, vector<ll>(5, 0));
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    memset(dp.data(), 0, dp.size() * sizeof dp[0]);
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
}