#include <iostream>
#include <cstring>
using namespace std;

inline int min_val(int a, int b) { return (a < b) ? a : b; } // inline function for minimum value

int main() {
  const int INF = 1000000000;
  int n, c;
  static int dp[2][5002][2];

  // Use memset to initialize the array
  memset(dp, INF, sizeof(dp));
  
  dp[1][1][0] = 0;
  dp[1][0][1] = 0;

  cin >> n; // Use cin for faster input
  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    cin >> c; // Use cin for faster input
    for (int j = 0; j <= n / 2; j++) {
      if (j == 0)
        dp[s][j][0] = INF;
      else
        dp[s][j][0] = min_val(dp[t][j - 1][0], dp[t][j - 1][1] + c);
      dp[s][j][1] = min_val(dp[t][j][0] + c, dp[t][j][1]);
    }
  }

  cout << min_val(dp[0][n / 2][0], dp[0][n / 2][1]); // Use cout for faster output
  return 0;
}