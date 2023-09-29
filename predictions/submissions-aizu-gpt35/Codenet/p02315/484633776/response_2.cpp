#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, W;
  cin >> N >> W;
  int value[N], weight[N];
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];
  int dp[2][10010];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < N; i++) {
    for (int w = 0; w <= W; w++) {
      if (w >= weight[i])
        dp[(i + 1) % 2][w] = max(dp[i % 2][w - weight[i]] + value[i], dp[i % 2][w]);
      else
        dp[(i + 1) % 2][w] = dp[i % 2][w];
    }
  }
  cout << dp[N % 2][W] << endl;
  return 0;
}