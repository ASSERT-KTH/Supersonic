#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  unsigned long long dp[4001][5];
  unsigned long long prefixSum[4001][5] = {0};

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4001; j++) {
      dp[j][i] = i == 1 && j <= 1000 ? 1 : 0;
      prefixSum[j][i] = j > 0 ? prefixSum[j - 1][i] : 0;
      prefixSum[j][i] += dp[j][i];
    }

  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= 4000; j++) {
      dp[j][i] += prefixSum[j][i - 1] - (j - 1001 >= 0 ? prefixSum[j - 1001][i - 1] : 0);
      prefixSum[j][i] = j > 0 ? prefixSum[j - 1][i] : 0;
      prefixSum[j][i] += dp[j][i];
    }

  int n;
  while (cin >> n)
    cout << dp[n][4] << endl;
  return 0;
}