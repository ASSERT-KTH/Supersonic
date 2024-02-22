#include <iostream>
using namespace std;

int solve(int n, int* t) {
  int dp[5002][2], tmp[5002][2];
  
  // Initialize dp and tmp arrays
  tmp[1][0] = tmp[0][1] = 0;

  for (int i = 1; i <= n/2; i++) {
    for (int pre = 0; pre < 2; pre++) {
      if (tmp[i-1][pre] == -1)
        continue;
      for (int next = 0; next < 2; next++) {
        if (pre == next) {
          if (next == 0)
            dp[i][next] = minCost(dp[i][next], tmp[i-1][pre]);
          else
            dp[i-1][next] = minCost(dp[i-1][next], tmp[i-1][pre]);
        } else {
          if (next == 0)
            dp[i][next] = minCost(dp[i][next], tmp[i-1][pre] + t[i-1]);
          else
            dp[i-1][next] = minCost(dp[i-1][next], tmp[i-1][pre] + t[i-1]);
        }
      }
    }
  }

  return minCost(dp[n/2][0], dp[n/2][1]);
}

int main() {
  int n;
  cin >> n;
  
  int t[n-1];
  for (int i = 0; i < n - 1; i++) {
    cin >> t[i];
  }
  
  cout << solve(n, t) << endl;
}