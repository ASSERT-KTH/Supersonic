#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define rep(i, n) for (int(i) = (0); (i) < (n); ++(i))

using namespace std;

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> weight(n), value(n);
  vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

  rep(i, n) cin >> value[i] >> weight[i];

  for (int i = 0; i < n; i++) {
    for (int w = 0; w <= W; w++) {
      if (w >= weight[i]) {
        dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
      } else {
        dp[i + 1][w] = dp[i][w];
      }
    }
  }
  cout << dp[n][W] << endl;
  return 0;
}