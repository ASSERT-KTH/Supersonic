#include <iostream>
using namespace std;

bool solve(int i, int m, int n, int* N) {
  bool dp[n+1][m+1];
  for (int i = 0; i <= n; i++) {
    dp[i][0] = true;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (N[i-1] > j) {
        dp[i][j] = dp[i-1][j];
      } else {
        dp[i][j] = dp[i-1][j] || dp[i-1][j-N[i-1]];
      }
    }
  }
  return dp[n][m];
}

int main() {
  int n, t;
  cin >> n;
  int N[1000];
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  cin >> t;
  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;
    if (solve(0, p, n, N)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}