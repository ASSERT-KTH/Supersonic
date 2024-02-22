#include <iostream>
using namespace std;

int main() {
  int64_t N, W;
  cin >> N >> W;
  int64_t value[N], weight[N];
  for (int64_t i = 0; i < N; i++)
    cin >> value[i] >> weight[i];
  int64_t dp[W+1];
  for (int64_t i = 0; i <= W; i++)
    dp[i] = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t w = W; w >= weight[i]; w--) {
      dp[w] = max(dp[w - weight[i]] + value[i], dp[w]);
    }
  }
  cout << dp[W] << endl;
  return 0;
}