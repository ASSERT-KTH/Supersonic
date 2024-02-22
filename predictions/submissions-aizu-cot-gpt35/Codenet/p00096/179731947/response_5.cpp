#include <iostream>
using namespace std;

int main() {
  unsigned int dp[4001][5];
  for (unsigned int i = 0; i < 5; i++)
    for (unsigned int j = 0; j < 4001; j++)
      dp[j][i] = (i == 1 && j <= 1000) ? 1 : 0;
  for (unsigned int i = 2; i <= 4; i++)
    for (unsigned int j = 0; j <= 4000; j++)
      for (unsigned int k = 0; k <= j; k++)
        dp[j][i] += dp[j - k][i - 1];
  unsigned int n;
  while (cin >> n)
    cout << dp[n][4] << endl;
  return 0;
}