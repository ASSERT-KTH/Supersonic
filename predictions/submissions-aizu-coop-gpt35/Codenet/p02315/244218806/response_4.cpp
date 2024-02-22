#include <iostream>
using namespace std;

const int MAX_N = 1000;
const int MAX_W = 10000;

int dp[MAX_W + 1];

int main() {
  int N, W;
  cin >> N >> W;
  int v[MAX_N], w[MAX_N];
  for (int i = 0; i < N; i++) {
    cin >> v[i] >> w[i];
  }

  for (int i = N - 1; i >= 0; i--) {
    for (int j = W; j >= w[i]; j--) {
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }

  cout << dp[W] << endl;
  return 0;
}