#include <iostream>
using namespace std;

const int MAX_N = 110;
const int MAX_W = 10010;
int n, W;
int weight[MAX_N], value[MAX_N];
int dp[MAX_N][MAX_W];

int main() {
  cin >> n >> W;
  for (int i = 0; i < n; i++) {
    cin >> value[i] >> weight[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= W; w++) {
      if (w >= weight[i]) {
        dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
      } else {
        dp[i + 1][w] = dp[i][w];
      }
    }
  }
  cout << dp[n][W] << endl;
  return 0;
}