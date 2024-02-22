#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  
  vector<int> value(N), weight(N);
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];
    
  vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
  
  for (int i = 0; i < N; i++) {
    for (int w = weight[i]; w <= W; w++) {
      dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
    }
    // copy the rest of the dp values from the previous row
    for (int w = 0; w < weight[i]; w++) {
      dp[i + 1][w] = dp[i][w];
    }
  }
  
  cout << dp[N][W] << endl;
  return 0;
}