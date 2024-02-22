for (int i = 1; i <= 4; i++) {
  for (int j = 1; j <= 4000; j++) {
    dp[j][i] += dp[j][i - 1];
  }
}