#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
  int n, W;
  cin >> n >> W;
  
  vector<int> weight(n), value(n);
  for (int i = 0; i < n; i++)
    cin >> value[i] >> weight[i];
  
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
  
  for (int i = 1; i <= n; i++) {
    for (int w = 1; w <= W; w++) {
      if (w >= weight[i - 1]) {
        dp[i][w] = max(dp[i - 1][w - weight[i - 1]] + value[i - 1], dp[i - 1][w]);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }
  
  cout << dp[n][W] << endl;
  
  return 0;
}