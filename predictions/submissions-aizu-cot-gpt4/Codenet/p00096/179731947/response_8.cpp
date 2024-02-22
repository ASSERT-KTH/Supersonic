#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  unsigned long long dp[4001][2];
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4001; j++)
      dp[j][i % 2] = i == 1 && j <= 1000 ? 1 : 0;
  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= 4000; j++)
      for (int k = 0; k <= min(j, 1000); k++)
        dp[j][i % 2] += dp[j - k][(i-1) % 2];
  int n;
  while (cin >> n)
    cout << dp[n][4 % 2] << "\n";
  return 0;
}