#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, W;
  cin >> N >> W;
  int value[N], weight[N];
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];
  int dp[2][W+1];
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    int cur = (i + 1) % 2;
    int prev = i % 2;
    for (int w = 0; w <= W; w++) {
      if (w < weight[i])
        dp[cur][w] = dp[prev][w];
      else
        dp[cur][w] = max(dp[prev][w - weight[i]] + value[i], dp[prev][w]);
    }
  }
  cout << dp[N % 2][W] << endl;
  return 0;
}