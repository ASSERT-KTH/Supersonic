#include <iostream>
#include <cstring>
using namespace std;

int main() {
  constexpr int INF = 1000000000;
  int n, c;
  static int dp[2][5000 + 2][2];

  memset(dp, INF, sizeof(dp));
  dp[1][1][0] = 0;
  dp[1][0][1] = 0;
  
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int s = i % 2;
    cin >> c;
    for (int j = 0; j <= n / 2; j++) {
      if (j == 0)
        dp[s][j][0] = INF;
      else {
        int temp1 = dp[(i - 1) % 2][j - 1][0];
        int temp2 = dp[(i - 1) % 2][j - 1][1] + c;
        dp[s][j][0] = min(temp1, temp2);
      }
      int temp3 = dp[(i - 1) % 2][j][0] + c;
      int temp4 = dp[(i - 1) % 2][j][1];
      dp[s][j][1] = min(temp3, temp4);
    }
  }

  cout << min(dp[0][n / 2][0], dp[0][n / 2][1]) << endl;
}