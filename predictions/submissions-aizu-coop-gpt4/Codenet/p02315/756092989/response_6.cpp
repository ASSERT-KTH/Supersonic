#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, W;
int weight[110], value[110];
int **dp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> W;

  dp = new int*[n+1];
  for(int i=0; i<=n; i++) {
    dp[i] = new int[W+1];
  }

  for(int i=0; i<n; i++) {
    cin >> value[i] >> weight[i];
  }

  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < n; i++) {
    for (int w = 0; w <= W; w++) {
      if (w >= weight[i]) {
        dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
      } else {
        dp[i + 1][w] = dp[i][w];
      }
    }
  }

  cout << dp[n][W] << endl;

  for(int i=0; i<=n; i++) {
    delete [] dp[i];
  }
  delete [] dp;

  return 0;
}