#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  unsigned long long dp[4001][5] = {0};
  for (int j = 0; j <= 4000; j++)
    dp[j][1] = j <= 1000 ? 1 : 0;
  for (int i = 2; i <= 4; i++)
    for (int j = i; j <= 4000; j++)
      dp[j][i] = dp[j - 1][i] + dp[j - 1][i - 1] - (j > 1000 ? dp[j - 1001][i - 1] : 0);
  int n;
  while (cin >> n)
    cout << dp[n][4] << endl;
  return 0;
}