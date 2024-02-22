#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int>& N, int m) {
  int n = N.size();
  vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
  dp[0][0] = true;
  
  for (int i = 1; i <= n; i++) {
    dp[i][0] = true;
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = dp[i-1][j];
      if (j >= N[i-1]) {
        dp[i][j] = dp[i][j] || dp[i-1][j-N[i-1]];
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
    if (solve(N, p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}