#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
  unsigned long long dp[5][4001];
  
  memset(dp, 0, sizeof(dp));
  for (int j = 0; j <= 1000; j++)
    dp[1][j] = 1;

  for (int i = 2; i <= 4; i++) {
    for (int j = 0; j <= 4000; j++) {
      for (int k = 0; k <= min(j, 1000); k++) {
        dp[i][j] += dp[i - 1][j - k];
      }
    }
  }

  int n;
  while (cin >> n)
    cout << dp[4][n] << endl;
  
  return 0;
}