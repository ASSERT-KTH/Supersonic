#include <iostream>
#include <vector>
using namespace std;
int main() {
  unsigned long long dp[4001][4], sum[4001][5] = {0};
  
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4001; j++)
      dp[j][i] = i == 0 && j <= 1000 ? 1 : 0;
  
  for (int i = 1; i <= 3; i++)
    for (int j = 0; j <= 4000; j++) {
      dp[j][i] = sum[j][i - 1];
      if (j > 0) {
        sum[j][i] = sum[j - 1][i] + dp[j][i];
      }
    }
  
  int n;
  while (cin >> n)
    cout << dp[n][3] << endl;
  return 0;
}