#include <iostream>
#include <algorithm>
using namespace std;

int a[101];
long long dp[101][21];

int main() {
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  dp[1][a[1]] = 1;
  for (int i = 2; i < N; i++) {
    for (int j = 0; j <= min(20, 20 - a[i]); j++) {
      dp[i][j] += dp[i - 1][j - a[i]];
    }
    for (int j = max(0, a[i]); j <= 20; j++) {
      dp[i][j] += dp[i - 1][j + a[i]];
    }
  }
  cout << dp[N - 1][a[N]] << endl;
  return 0;
}