#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  unsigned long long dp[4001][5];
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4001; j++)
      dp[j][i] = i == 1 && j <= 1000 ? 1 : 0;
  for (int i = 2; i <= 4; i++) {
    dp[0][i] = 1;
    for (int j = 1; j <= 4000; j++)
        dp[j][i] = dp[j][i - 1] + dp[j - 1][i];
  }
  int n;
  while (cin >> n)
    cout << dp[n][4] << endl;
  return 0;
}