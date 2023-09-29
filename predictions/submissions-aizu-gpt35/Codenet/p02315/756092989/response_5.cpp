#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 100010;
int n, W;
int weight[MX], value[MX];
int dp[MX];
int main() {
  cin >> n >> W;
  for (int i = 0; i < n; i++) {
    cin >> value[i] >> weight[i];
  }
  for (int i = 0; i < n; i++) {
    for (int w = W; w >= weight[i]; w--) {
      dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
    }
  }
  cout << dp[W] << endl;
  return 0;
}