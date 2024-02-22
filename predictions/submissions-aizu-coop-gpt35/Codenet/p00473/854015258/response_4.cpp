#include <iostream>
using namespace std;

int main() {
  const int INF = 1000000000;
  int n, c;

  // Use a 2D array instead of a 3D array
  static int dp[2][5000 + 2];

  // Initialize the first row of the dp array
  for (int j = 0; j < 5002; j++) {
    dp[0][j] = INF;
    dp[1][j] = INF;
  }

  dp[1][1] = 0;
  dp[1][0] = 0;

  cin >> n;
  for (int i = 2; i <= n; i++) {
    int s = i % 2;
    int t = 1 - s;
    cin >> c;

    // Store the values in variables to avoid redundant calculations
    int prev0 = INF;
    int prev1 = INF;

    for (int j = 0; j <= n / 2; j++) {
      if (j == 0)
        dp[s][j] = INF;
      else
        dp[s][j] = min(prev0, prev1 + c);

      // Update the previous values
      prev0 = dp[t][j][0];
      prev1 = dp[t][j][1];
    }
  }

  // Use cout for faster output
  cout << min(dp[0][n / 2], dp[1][n / 2]) << endl;
}