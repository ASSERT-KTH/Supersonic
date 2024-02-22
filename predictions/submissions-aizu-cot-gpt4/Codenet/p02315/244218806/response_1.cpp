#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0)); // dynamic allocation based on N and W
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j - w[i] < 0) {
        dp[i + 1][j] = dp[i][j];
      } else {
        int newValue = dp[i][j - w[i]] + v[i]; // calculate this only once
        dp[i + 1][j] = max(dp[i][j], newValue);
      }
    }
  }
  cout << dp[N][W] << endl;
  return 0;
}