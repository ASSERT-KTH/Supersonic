#include <iostream>
using namespace std;
int a[101];
long long dp[2][21];
int main() {
  int i, j;
  int N;
  cin >> N;
  for (i = 0; i <= 20; i++) {
    dp[0][i] = 0;
  }
  for (i = 1; i <= N; i++) {
    cin >> a[i];
    for (j = 0; j <= 20; j++) {
      dp[i % 2][j] = 0;
    }
    if (i == 1) {
      dp[1][a[1]] = 1;
      continue;
    }
    for (j = 0; j <= 20; j++) {
      if (j - a[i] >= 0) {
        dp[i % 2][j] += dp[(i - 1) % 2][j - a[i]];
      }
      if (j + a[i] <= 20) {
        dp[i % 2][j] += dp[(i - 1) % 2][j + a[i]];
      }
    }
  }
  cout << dp[N % 2][a[N]] << endl;
  return 0;
}