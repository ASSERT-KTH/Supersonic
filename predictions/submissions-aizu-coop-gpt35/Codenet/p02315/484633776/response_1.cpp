#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;
  
  vector<int> value(N), weight(N);
  for (int i = 0; i < N; i++)
    cin >> value[i] >> weight[i];

  int dp[110][10010] = {0};

  for (int i = 0; i < N; i++) {
    for (int w = 0; w < W; w += 8) {
      int max_value[8] = {0};
      int max_weight[8] = {0};

      for (int j = 0; j < 8; j++) {
        if (w + j < W) {
          max_value[j] = dp[i][w + j - weight[i]] + value[i];
          max_weight[j] = dp[i][w + j];
        }
      }

      for (int j = 0; j < 8; j++) {
        if (w + j < W) {
          dp[i + 1][w + j] = max(max_value[j], max_weight[j]);
        }
      }
    }
  }

  cout << dp[N][W] << endl;
  return 0;
}