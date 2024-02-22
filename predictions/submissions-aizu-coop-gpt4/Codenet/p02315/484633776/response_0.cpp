#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 110;
const int MAX_W = 10010;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> value(N), weight(N);
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];
    
  vector<int> dp(MAX_W, 0);
  for (int i = 0; i < N; i++) {
    for (int w = W; w >= weight[i]; w--) { // reverse order to avoid overwriting previous row's values
      dp[w] = max(dp[w - weight[i]] + value[i], dp[w]);
    }
  }
  
  cout << dp[W] << endl;
  return 0;
}