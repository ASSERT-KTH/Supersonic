#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];

  int* dp = new int[W + 1];
  for (int j = 0; j <= W; j++)
    dp[j] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = W; j >= w[i]; j--) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }

  cout << dp[W] << endl;

  delete[] dp;
  return 0;
}