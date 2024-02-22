#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];

  // Change to dynamic 2D vector
  vector<vector<int>> dp(N + 1, vector<int>(W + 1));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < w[i]; j++) {
      dp[i + 1][j] = dp[i][j];
    }
    for (int j = w[i]; j <= W; j++) {
      dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
    }
  }
  cout << dp[N][W] << endl;
  return 0;
}