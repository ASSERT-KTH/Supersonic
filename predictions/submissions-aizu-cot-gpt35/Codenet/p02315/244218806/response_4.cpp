#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);

  int N, W;
  std::cin >> N >> W;

  std::vector<int> v(N), w(N);
  for (int i = 0; i < N; i++)
    std::cin >> v[i] >> w[i];

  std::vector<int> dp(W + 1, 0);

  for (int i = 0; i < N; i++) {
    for (int j = W; j >= w[i]; j--) {
      int temp = dp[j - w[i]] + v[i];
      if (temp > dp[j])
        dp[j] = temp;
    }
  }

  std::cout << dp[W] << "\n";

  return 0;
}