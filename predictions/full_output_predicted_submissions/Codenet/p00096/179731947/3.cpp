#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  long long dp[4001][5];
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4001; j++)
      dp[j][i] = i == 1 && j <= 1000 ? 1 : 0;
  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= 4000; j++)
      for (int k = 0; k <= j && k <= 1000; k++)
        dp[j][i] += dp[j - k][i - 1];
  int n;
  while (cin >> n)
    cout << dp[n][4] << endl;
  return 0;
}
