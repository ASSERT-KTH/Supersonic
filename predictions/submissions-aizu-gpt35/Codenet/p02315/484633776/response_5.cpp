#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, W;
  cin >> N >> W;
  vector<int> value(N), weight(N);
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];
  vector<vector<int>> dp(N + 1, vector<int>(W + 1));
  for (int i = 0; i < N; i++) {
    for (int w = 0; w <= W; w++) {
      if (w >= weight[i])
        dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
      else
        dp[i + 1][w] = dp[i][w];
    }
  }
  cout << dp[N][W] << endl;
  return 0;
}