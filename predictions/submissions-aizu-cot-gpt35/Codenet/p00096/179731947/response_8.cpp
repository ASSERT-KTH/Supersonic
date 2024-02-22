#include <iostream>
#include <vector>

const int MAX_N = 4001;
const int MAX_K = 4;
const int MAX_X = 1000;

int main() {
  std::vector<std::vector<unsigned long long>> dp(MAX_N, std::vector<unsigned long long>(MAX_K + 1));

  for (int i = 0; i < MAX_K + 1; i++) {
    for (int j = 0; j < MAX_N; j++) {
      dp[j][i] = (i == 1 && j <= MAX_X) ? 1 : 0;
    }
  }

  for (int i = 2; i <= MAX_K; i++) {
    for (int j = 0; j < MAX_N; j++) {
      for (int k = 0; k <= std::min(j, MAX_X); k++) {
        dp[j][i] += dp[j - k][i - 1];
      }
    }
  }

  std::ios_base::sync_with_stdio(false);

  int n;
  while (std::cin >> n) {
    std::cout << dp[n][MAX_K] << std::endl;
  }

  return 0;
}