#include <iostream>
#include <cstring>
using namespace std;

int dp[1000000][5];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    dp[0][0] = 1;
    for (int i = 1; i * i <= n; i++) {
      int sq = i * i;                  // Compute i*i only once
      for (int k = 1; k <= 4; k++) {
        for (int j = sq; j <= n; j++) {
          dp[j][k] += dp[j - sq][k - 1];
        }
      }
    }
    cout << dp[n][4] + dp[n][3] + dp[n][2] + dp[n][1] << "\n";
  }
}