#include <iostream>
#include <cstring>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int INF = 1000000000;
  int n, c;
  
  cin >> n;
  
  static int dp[2][n/2 + 1][2];
  memset(dp, INF, sizeof(dp));
  
  dp[1][1][0] = 0;
  dp[1][0][1] = 0;

  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    cin >> c;
    
    dp[s][0][0] = INF;
    
    for (int j = 1; j <= n / 2; j++) {
      dp[s][j][0] = min(dp[t][j - 1][0], dp[t][j - 1][1] + c);
      dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
    }
  }
  
  cout << min(dp[0][n / 2][0], dp[0][n / 2][1]) << "\n";

  return 0;
}