#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> value(N), weight(N);
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];
  vector<int> dp(W + 1, 0); // Initialize dp array with 0s
  for (int i = 0; i < N; i++) {
    for (int w = W; w >= weight[i]; w--) { // Modify loop condition
      dp[w] = max(dp[w - weight[i]] + value[i], dp[w]);
    }
  }
  cout << dp[W] << endl;
  return 0;
}