#include <iostream>
#include <vector>
using namespace std;

vector<int> N;
int n;

bool solve(int m) {
  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
  dp[0][0] = true;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      if (j < N[i]) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = dp[i][j] || dp[i][j - N[i]];
      }
    }
  }

  return dp[n][m];
}

int main() {
  int t;
  cin >> n;
  N.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  cin >> t;
  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;
    if (solve(p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}