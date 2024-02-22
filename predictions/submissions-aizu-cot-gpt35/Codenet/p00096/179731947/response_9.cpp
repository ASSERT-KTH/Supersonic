#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<unsigned long long>> dp(4001, std::vector<unsigned long long>(5, 0));

  for (int j = 0; j < 4001; j++) {
    dp[j][1] = (j <= 1000) ? 1 : 0;
  }

  for (int i = 2; i <= 4; i++) {
    for (int j = 0; j <= 4000; j++) {
      for (int k = 0; k <= j && k <= 1000; k++) {
        dp[j][i] += dp[j - k][i - 1];
      }
    }
  }

  int n;
  while (std::cin >> n) {
    std::cout << dp[n][4] << std::endl;
  }

  return 0;
}