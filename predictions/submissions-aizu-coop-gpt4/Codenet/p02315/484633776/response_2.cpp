#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, W;
  cin >> N >> W;
  vector<int> value(N), weight(N);
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];
  
  vector<vector<int>> dp(2, vector<int>(W + 1, 0));
  for (int i = 0; i < N; i++) {
    for (int w = weight[i]; w <= W; w++) {
      dp[(i + 1) % 2][w] = max(dp[i % 2][w - weight[i]] + value[i], dp[i % 2][w]);
    }
    // Copy the remaining values from the previous row
    if(i < N-1)
      copy(dp[i % 2].begin() + weight[i+1], dp[i % 2].end(), dp[(i+1) % 2].begin() + weight[i+1]);
  }
  cout << dp[N % 2][W] << endl;
  return 0;
}