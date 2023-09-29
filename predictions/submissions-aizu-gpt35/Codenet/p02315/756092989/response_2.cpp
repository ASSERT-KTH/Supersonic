#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, W;
int weight[110], value[110];
int dp[10010];

int main() {
  cin >> n >> W;
  for (int i = 0; i < n; i++) cin >> value[i] >> weight[i];
  for (int i = 0; i < n; i++) {
    for (int w = W; w >= weight[i]; w--) {
      dp[w] = max(dp[w - weight[i]] + value[i], dp[w]);
    }
  }
  cout << dp[W] << endl;
  return 0;
}