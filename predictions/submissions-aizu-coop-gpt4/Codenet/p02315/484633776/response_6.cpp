#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, W;
  cin >> N >> W;
  int value[N], weight[N];
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];
  // Optimized dp array to use only 2 rows
  int dp[2][10010];
  for (int i = 0; i <= W; i++)
    dp[0][i] = 0;
  for (int i = 0; i < N; i++) {
    for (int w = 0; w <= W; w++) {
      // Use modulo operation to alternate between 0 and 1 for current and previous row
      if (w >= weight[i])
        dp[(i + 1) % 2][w] = max(dp[i % 2][w - weight[i]] + value[i], dp[i % 2][w]);
      else
        dp[(i + 1) % 2][w] = dp[i % 2][w];
    }
  }
  // Output result from the last computed row
  cout << dp[N % 2][W] << endl;
  return 0;
}