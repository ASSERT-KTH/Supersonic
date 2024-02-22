#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];
  vector<int> dp(W + 1, 0); // 1D array instead of 2D array
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j += 4) { // Unroll loop by a factor of 4
      if (j - w[i] >= 0) {
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
      }
      if (j + 1 - w[i] >= 0) {
        dp[j + 1] = max(dp[j + 1], dp[j + 1 - w[i]] + v[i]);
      }
      if (j + 2 - w[i] >= 0) {
        dp[j + 2] = max(dp[j + 2], dp[j + 2 - w[i]] + v[i]);
      }
      if (j + 3 - w[i] >= 0) {
        dp[j + 3] = max(dp[j + 3], dp[j + 3 - w[i]] + v[i]);
      }
    }
  }
  cout << dp[W] << endl;
  return 0;
}