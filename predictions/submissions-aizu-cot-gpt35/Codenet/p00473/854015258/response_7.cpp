#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1000000000;

int main() {
  int n, c;
  int dp[2][5000 + 2][2];

  memset(dp, INF, sizeof(dp));
  
  dp[1][1][0] = 0;
  dp[1][0][1] = 0;

  cin >> n;
  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    cin >> c;
    for (int j = 0; j <= (n >> 1); j++) {
      dp[s][j][0] = min(dp[t][j - 1][0], dp[t][j - 1][1] + c);
      dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
    }
  }
  
  cout << min(dp[0][n >> 1][0], dp[0][n >> 1][1]) << endl;

  return 0;
}