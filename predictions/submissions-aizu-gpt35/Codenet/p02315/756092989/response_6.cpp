#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100010;
int n, W, dp[2][MAX_N];
int main() {
  cin >> n >> W;
  for (int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;
    for (int j = 0; j <= W; j++) {
      if (j >= w) {
        dp[(i + 1) & 1][j] = max(dp[i & 1][j - w] + v, dp[i & 1][j]);
      } else {
        dp[(i + 1) & 1][j] = dp[i & 1][j];
      }
    }
  }
  cout << dp[n & 1][W] << endl;
  return 0;
}