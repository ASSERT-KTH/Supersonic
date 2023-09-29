#include <iostream>
#include <algorithm>
#define ll long long
#define rep(i, n) for (int(i) = (0); (i) < (n); ++(i))

int n, W;
int weight[110], value[110];
int dp[110][10010];

int main() {
  std::ios_base::sync_with_stdio(false); 
  std::cin.tie(NULL);
  std::cin >> n >> W;
  rep(i, n) std::cin >> value[i] >> weight[i];
  std::fill(dp[0], dp[0] + W + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int w = 0; w <= W; w++) {
      if (w >= weight[i]) {
        dp[i + 1][w] = std::max(dp[i][w - weight[i]] + value[i], dp[i][w]);
      } else {
        dp[i + 1][w] = dp[i][w];
      }
    }
  }
  std::cout << dp[n][W] << '\n';
  return 0;
}