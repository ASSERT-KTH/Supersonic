#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];

  vector<vector<int>> dp(2, vector<int>(W + 1, 0));
  for (int i = 0; i < N; i++) {
    int cur = i % 2;
    int prev = 1 - cur;
    for (int j = 0; j <= W; j++) {
      if (j < w[i]) {
        dp[cur][j] = dp[prev][j];
      } else {
        dp[cur][j] = max(dp[prev][j], dp[prev][j - w[i]] + v[i]);
      }
    }
  }
  cout << dp[(N - 1) % 2][W] << endl;
  return 0;
}