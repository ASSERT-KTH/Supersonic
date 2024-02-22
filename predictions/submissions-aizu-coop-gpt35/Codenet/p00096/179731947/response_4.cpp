#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<vector<unsigned long long>> dp(5, vector<unsigned long long>(4001, 0));

  // Initialize dp
  for (int j = 0; j <= 1000; j++) {
    dp[1][j] = 1;
  }

  for (int i = 2; i <= 4; i++) {
    vector<vector<unsigned long long>> prev_dp = dp;

    for (int j = 0; j <= 4000; j++) {
      dp[i][j] = 0;

      for (int k = 0; k <= min(j, 1000); k++) {
        dp[i][j] += prev_dp[i - 1][j - k];
      }
    }
  }

  int n;
  while (cin >> n) {
    cout << dp[4][n] << endl;
  }

  return 0;
}