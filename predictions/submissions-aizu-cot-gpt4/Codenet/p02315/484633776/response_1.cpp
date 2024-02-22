#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  int value[N], weight[N];
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];
  
  int **dp = new int*[N+1];
  for(int i = 0; i <= N; i++)
    dp[i] = new int[W+1];

  memset(dp, 0, sizeof(dp[0][0]) * (N + 1) * (W + 1));

  for (int i = 0; i < N; i++) {
    for (int w = weight[i]; w <= W; w++) {
      dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
    }
    for (int w = 0; w < weight[i]; w++) {
      dp[i + 1][w] = dp[i][w];
    }
  }

  cout << dp[N][W] << endl;

  for(int i = 0; i <= N; i++)
    delete [] dp[i];
  delete [] dp;

  return 0;
}