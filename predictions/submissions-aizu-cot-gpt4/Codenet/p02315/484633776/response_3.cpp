#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int N, W;
  std::cin >> N >> W;
  std::vector<int> value(N), weight(N);
  for (int i = 0; i < N; i++)
    std::cin >> value[i] >> weight[i];
  std::vector<int> dp(W + 1, 0); // Declare and initialize dp vector
  for (int i = 0; i < N; i++) {
    for (int w = W; w >= weight[i]; w--) {
      dp[w] = std::max(dp[w - weight[i]] + value[i], dp[w]);
    }
  }
  std::cout << dp[W] << std::endl;
  return 0;
}