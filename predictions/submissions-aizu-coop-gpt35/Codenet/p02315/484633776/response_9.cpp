#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;

  vector<int> value(N), weight(N);
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];

  vector<int> dp(W + 1, 0); // Use a 1D vector instead of a 2D array

  for (int i = 0; i < N; i++) {
    for (int w = W; w >= weight[i]; w--) { // Optimize the inner loop
      int temp = dp[w - weight[i]] + value[i]; // Use a temporary variable
      dp[w] = max(dp[w], temp);
    }
  }

  cout << dp[W] << endl;

  return 0;
}