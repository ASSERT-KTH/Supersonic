#include <iostream>
using namespace std;
int a[101];
long long dp[110][21];
int main() {
  int i, j;
  int N;
  cin >> N;
  for (i = 0; i <= 100; i++) {
    for (j = 0; j <= 20; j++) {
      dp[i][j] = 0;
    }
  }
  for (i = 1; i <= N; i++) {
    cin >> a[i];
  }
  dp[1][a[1]] = 1;
  for (i = 2; i < N; i++) {
    for (j = 0; j <= 20; j++) {
      if (j - a[i] >= 0)
        dp[i][j] += dp[i - 1][j - a[i]];
      if (j + a[i] <= 20) {
        dp[i][j] += dp[i - 1][j + a[i]];
        break;
      }
    }
  }
  cout << dp[N - 1][a[N]] << endl;
  return 0;
}
