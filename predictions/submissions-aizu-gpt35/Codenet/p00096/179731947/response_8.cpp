#include <iostream>
#include <vector>
using namespace std;

int main() {
  const int MAX_N = 4000;
  vector<vector<unsigned long long>> dp(5, vector<unsigned long long>(MAX_N + 1, 0));
  for (int i = 1; i <= MAX_N; ++i) dp[1][i] = (i <= 1000 ? 1 : 0);
  for (int i = 2; i <= 4; ++i)
    for (int j = i; j <= MAX_N; ++j)
      dp[i][j] = dp[i - 1][j - 1] + dp[i][j - i];
  int n;
  while (cin >> n) cout << dp[4][n] << endl;
  return 0;
}