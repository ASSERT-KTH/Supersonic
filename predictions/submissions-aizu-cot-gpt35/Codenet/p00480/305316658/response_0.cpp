#include <iostream>

int a[101];
long long dp[110][21];

int main() {
  int i, j;
  int N;
  std::cin >> N;

  for (i = 1; i <= N; i++) {
    std::cin >> a[i];
  }

  dp[1][a[1]] = 1;

  for (i = 2; i <= N; i++) {
    for (j = 0; j <= 20; j++) {
      if (j - a[i] >= 0)
        dp[i][j] += dp[i - 1][j - a[i]] + dp[i - 1][j + a[i]];
      else if (j + a[i] <= 20)
        dp[i][j] += dp[i - 1][j + a[i]];
    }
  }

  std::cout << dp[N][a[N]] << std::endl;

  return 0;
}