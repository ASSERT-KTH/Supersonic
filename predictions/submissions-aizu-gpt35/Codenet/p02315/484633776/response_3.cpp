#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, W;
  cin >> N >> W;
  vector<int> value(N), weight(N);
  for (int i = 0; i < N; i++) {
    cin >> value[i] >> weight[i];
  }
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int w = 1; w <= W; w++) {
      if (w >= weight[i - 1]) {
        dp[i][w] = max(dp[i - 1][w - weight[i - 1]] + value[i - 1], dp[i - 1][w]);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }
  cout << dp[N][W] << endl;
  return 0;
}