#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int maxn = 4000;
  vector<vector<unsigned long long>> dp(maxn+1, vector<unsigned long long>(5, 0));
  for (int i = 0; i < 5; i++)
    for (int j = 0; j <= min(maxn, 1000); j++)
      dp[j][i] = i == 1 ? 1 : 0;
  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= maxn; j++) {
      dp[j][i] = dp[j][i-1];
      if (j > 0)
        dp[j][i] += dp[j - 1][i];
      if (j > 1000)
        dp[j][i] -= dp[j - 1001][i - 1];
    }
  int n;
  while (cin >> n)
    cout << dp[min(n, maxn)][4] << endl;
  return 0;
}