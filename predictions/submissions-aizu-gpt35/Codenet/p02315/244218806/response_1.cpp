#include <iostream>
#include <vector>
using namespace std;
int dp[2][10001];
int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j - w[i] < 0) {
        dp[(i + 1) % 2][j] = dp[i % 2][j];
      } else {
        dp[(i + 1) % 2][j] = max(dp[i % 2][j], dp[i % 2][j - w[i]] + v[i]);
      }
    }
  }
  cout << dp[N % 2][W] << endl;
  return 0;
}