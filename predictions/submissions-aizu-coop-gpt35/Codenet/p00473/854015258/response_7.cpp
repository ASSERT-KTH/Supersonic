#include <iostream>
using namespace std;

int main() {
  const unsigned int INF = 1000000000;
  unsigned int n, c;
  cin >> n;

  // Dynamic allocation of the dp array
  unsigned int*** dp = new unsigned int**[2];
  for (unsigned int i = 0; i < 2; i++) {
    dp[i] = new unsigned int*[n / 2 + 1];
    for (unsigned int j = 0; j <= n / 2; j++) {
      dp[i][j] = new unsigned int[2];
      dp[i][j][0] = INF;
      dp[i][j][1] = INF;
    }
  }

  dp[1][1][0] = 0;
  dp[1][0][1] = 0;

  for (unsigned int i = 2; i <= n; i++) {
    unsigned int s = i % 2;
    unsigned int t = 1 - s;
    cin >> c;

    // Optimized inner loop
    for (unsigned int j = 1; j <= n / 2; j++) {
      dp[s][j][0] = min(dp[t][j - 1][0], dp[t][j - 1][1] + c);
      dp[s][j][1] = min(dp[t][j][0] + c, dp[t][j][1]);
    }
  }

  cout << min(dp[0][n / 2][0], dp[0][n / 2][1]) << endl;

  // Freeing the dynamically allocated memory
  for (unsigned int i = 0; i < 2; i++) {
    for (unsigned int j = 0; j <= n / 2; j++) {
      delete[] dp[i][j];
    }
    delete[] dp[i];
  }
  delete[] dp;

  return 0;
}