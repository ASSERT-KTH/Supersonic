#include <iostream>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  int value[N], weight[N];
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];

  int** dp = new int*[N+1];
  for (int i = 0; i <= N; i++)
    dp[i] = new int[W+1];

  for (int i = 0; i <= N; i++)
    dp[i][0] = 0;

  for (int i = 0; i <= W; i++)
    dp[0][i] = 0;

  for (int i = 0; i < N; i++) {
    for (int w = 1; w < W; w++) {
      if (w >= weight[i])
        dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
      else
        dp[i + 1][w] = dp[i][w];
    }
  }

  cout << dp[N][W] << endl;

  for (int i = 0; i <= N; i++)
    delete[] dp[i];
  delete[] dp;

  return 0;
}