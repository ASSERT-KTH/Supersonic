#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int dp[2][5001][2];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, c;
  fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(dp[0][0][0]), INF);

  dp[1][1][0] = 0;
  dp[1][0][1] = 0;

  cin >> n;
  for (int i = 2; i <= n; i++) {
    int s = i % 2, t = 1 - s;
    cin >> c;
    for (int j = 0; j <= n / 2; j++) {
      dp[s][j][0] = j > 0 ? min(dp[t][j - 1][0], dp[t][j - 1][1] + c) : INF;
      dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
    }
  }
  cout << min(dp[0][n / 2][0], dp[0][n / 2][1]) << "\n";
}