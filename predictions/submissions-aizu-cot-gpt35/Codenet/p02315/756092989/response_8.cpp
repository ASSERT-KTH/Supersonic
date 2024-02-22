#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> weight(n), value(n);
  for (int i = 0; i < n; i++) {
    cin >> value[i] >> weight[i];
  }
  vector<vector<int>> dp(2, vector<int>(W + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int w = weight[i]; w <= W; w++) {
      dp[(i + 1) % 2][w] = max(dp[i % 2][w - weight[i]] + value[i], dp[i % 2][w]);
    }
  }
  cout << dp[n % 2][W] << endl;
  return 0;
}