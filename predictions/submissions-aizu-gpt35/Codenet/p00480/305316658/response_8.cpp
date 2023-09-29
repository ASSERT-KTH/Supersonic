#include <iostream>
using namespace std;
int a[101];
long long dp[110][21];
int main() {
  int i, j;
  int N;
  cin >> N;
  for (i = 0; i <= 20; i++) {
    dp[1][i] = 0;
  }
  cin >> a[1];
  dp[1][a[1]] = 1;
  for (i = 2; i <= N; i++) {
    cin >> a[i];
    for (j = 0; j <= 20; j++) {
      dp[i][j] = 0;
      if (j - a[i] >= 0)
        dp[i][j] += dp[i - 1][j - a[i]];
      if (j + a[i] <= 20)
        dp[i][j] += dp[i - 1][j + a[i]];
    }
  }
  cout << dp[N][a[N]] << endl;
  return 0;
}