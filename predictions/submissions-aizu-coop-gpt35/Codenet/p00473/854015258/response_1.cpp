#include <iostream>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp[2][5000 + 2];
  
  cin >> n;
  dp[1][1] = 0;
  dp[1][0] = 0;

  for (int i = 2; i <= n; i++) {
    int j;
    cin >> c;
    for (j = 0; j <= n / 2; j++) {
      if (j == 0)
        dp[i % 2][j] = INF;
      else
        dp[i % 2][j] = dp[(i - 1) % 2][j - 1] < dp[(i - 1) % 2][j - 1] + c ? dp[(i - 1) % 2][j - 1] : dp[(i - 1) % 2][j - 1] + c;
      dp[i % 2][j] = dp[(i - 1) % 2][j] + c < dp[(i - 1) % 2][j] ? dp[(i - 1) % 2][j] + c : dp[(i - 1) % 2][j];
    }
  }
  
  cout << (dp[0][n / 2] < dp[0][n / 2] ? dp[0][n / 2] : dp[0][n / 2]) << endl;
}