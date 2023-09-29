#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int N, W, value[MAXN], weight[MAXN], dp[2][10010];
int main() {
  cin >> N >> W;
  for (int i = 1; i <= N; i++)
    cin >> value[i] >> weight[i];
  for (int i = 1; i <= N; i++) {
    for (int w = 0; w <= W; w++) {
      if (w >= weight[i])
        dp[i % 2][w] = max(dp[(i - 1) % 2][w - weight[i]] + value[i], dp[(i - 1) % 2][w]);
      else
        dp[i % 2][w] = dp[(i - 1) % 2][w];
    }
  }
  cout << dp[N % 2][W] << endl;
  return 0;
}