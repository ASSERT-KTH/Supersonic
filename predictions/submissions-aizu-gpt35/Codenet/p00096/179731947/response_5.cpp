#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  unsigned long long dp[4001][5];
  for (int i = 0; i < 5; i++)
      dp[0][i] = 1;
  for (int i = 1; i <= 4000; i++)
    for (int j = 1; j < 5; j++)
      dp[i][j] = (i < j) ? dp[i][j-1] : dp[i][j-1]+dp[i-j][j];
  int n;
  while (cin >> n)
    cout << dp[n][4] << endl;
  return 0;
}