#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, W;
  cin >> n >> W;

  vector<int> weight(n);
  vector<int> value(n);
  for (int i = 0; i < n; i++) {
    cin >> value[i] >> weight[i];
  }

  vector<int> dp(W + 1, 0);  // Initialize dp array with size W+1 and all values as 0

  for (int i = 0; i < n; i++) {
    for (int w = W; w >= weight[i]; w--) {
      dp[w] = max(dp[w - weight[i]] + value[i], dp[w]);
    }
  }

  cout << dp[W] << endl;

  return 0;
}