#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, W;
  cin >> n >> W;
  vector<int> value(n), weight(n), dp(W+1, 0);
  
  for (int i=0; i<n; ++i) 
    cin >> value[i] >> weight[i];
    
  for (int i=0; i<n; ++i) {
    for (int w=W; w>=weight[i]; --w) {
      dp[w] = max(dp[w], dp[w-weight[i]] + value[i]);
    }
  }
  
  cout << dp[W] << endl;
  return 0;
}