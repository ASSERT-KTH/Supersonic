#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, W;
  cin >> N >> W;

  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];

  vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

  for (int i = 0; i < N; i++) {
    for (int j = w[i]; j <= W; j++) {
      dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
    }
    if (i < N-1)
      for (int j = 0; j < w[i+1]; ++j)
        dp[i + 1][j] = dp[i][j];
  }
  
  cout << dp[N][W] << '\n';

  return 0;
}