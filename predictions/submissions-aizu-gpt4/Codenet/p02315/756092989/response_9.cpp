#include <iostream>
#include <algorithm>

int main() {
  int n, W;
  std::cin >> n >> W;
  int weight[n], value[n], dp[W+1] = {0};
  
  for (int i = 0; i < n; i++) {
    std::cin >> value[i] >> weight[i];
  }
  
  for (int i = 0; i < n; i++) {
    for (int w = W; w >= weight[i]; w--) {
        dp[w] = std::max(dp[w - weight[i]] + value[i], dp[w]);
    }
  }
  
  std::cout << dp[W] << std::endl;
  return 0;
}