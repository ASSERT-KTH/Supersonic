#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  unsigned long long dp[n+1][5];
  
  for (int i = 0; i < 5; i++)
    for (int j = 0; j <= n; j++)
      dp[j][i] = i == 1 && j <= 1000 ? 1 : 0;
  
  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= min(j, 1000); k++)
        dp[j][i] += dp[j - k][i - 1];
  
  cout << dp[n][4] << endl;
  
  return 0;
}