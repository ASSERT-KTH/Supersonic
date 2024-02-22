#include <iostream>

int main() {
  unsigned int dp[4001 * 5] = {0};
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4001; j++)
      dp[j + i * 4001] = i == 1 && j <= 1000 ? 1 : 0;
  for (int i = 2; i <= 4; i++)
    for (int j = 0; j <= 4000; j++)
      for (int k = 0; k <= j && k <= 1000; k++)
        dp[j + i * 4001] += dp[j - k + (i - 1) * 4001];
  int n;
  while (std::cin >> n)
    std::cout << dp[n + 4 * 4001] << std::endl;
  return 0;
}