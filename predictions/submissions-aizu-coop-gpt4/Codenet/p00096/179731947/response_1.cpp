#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<vector<unsigned long long>> dp(4001, vector<unsigned long long>(5, 0));
  for (int i = 0; i < 5; i++)
    for (int j = 0; j <= 1000; j++)
      dp[j][i] = i == 1 ? 1 : 0;
  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= 4000; j++) {
      unsigned long long sum = 0;
      for (int k = 0; k <= j && k <= 1000; k++) {
        sum += dp[k][i - 1];
      }
      dp[j][i] = sum;
      if (j > 1000) {
        sum -= dp[j - 1001][i - 1];
      }
    }
  int n;
  while (cin >> n)
    cout << dp[n][4] << endl;
  return 0;
}