#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  
  int value[N], weight[N];
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];

  int dp[W + 1];
  memset(dp, 0, sizeof(dp)); // Initialize dp array to 0
  
  for (int i = 0; i < N; i++) {
    for (int w = W; w >= weight[i]; w--) {
      dp[w] = max(dp[w - weight[i]] + value[i], dp[w]);
    }
  }

  cout << dp[W] << endl;
  return 0;
}