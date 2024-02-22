#include <iostream>
#include <vector>
using namespace std;

bool solve(const vector<int>& N, int m, vector<vector<bool>>& dp) {
  int n = N.size();
  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j < N[i-1]) {
        dp[i][j] = dp[i-1][j];
      } else {
        dp[i][j] = dp[i-1][j] || dp[i-1][j-N[i-1]];
      }
    }
  }
  return dp[n][m];
}

int main() {
  int n;
  cin >> n;
  vector<int> N(n);
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;
    vector<vector<bool>> dp(n+1, vector<bool>(p+1, false));
    if (solve(N, p, dp)) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}