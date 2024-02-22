#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N);
  vector<int> w(N);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];

  vector<vector<int>> dp(N + 1, vector<int>(W + 1));

  for (int i = 0; i < N; i += 2) {
    for (int& j : dp[i]) {
      if (j - w[i] < 0) {
        j = dp[i][j];
      } else {
        j = max(dp[i][j], dp[i][j - w[i]] + v[i]);
      }
    }
    for (int& j : dp[i + 1]) {
      if (j - w[i + 1] < 0) {
        j = dp[i + 1][j];
      } else {
        j = max(dp[i + 1][j], dp[i + 1][j - w[i + 1]] + v[i + 1]);
      }
    }
  }

  cout << dp[N][W] << endl;

  return 0;
}