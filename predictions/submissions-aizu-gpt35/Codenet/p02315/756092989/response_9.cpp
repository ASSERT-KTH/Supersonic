#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100 + 10, MAX_W = 1e4 + 10;
int n, W, weight[MAX_N], value[MAX_N], dp[MAX_W];
int main() {
  cin >> n >> W;
  for (int i = 0; i < n; i++) {
    cin >> value[i] >> weight[i];
  }
  for (int i = 0; i < n; i++) {
    for (int w = W; w >= weight[i]; w--) {
      dp[w] = max(dp[w - weight[i]] + value[i], dp[w]);
    }
  }
  cout << dp[W] << endl;
  return 0;
}