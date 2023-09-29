#include <iostream>
#include <vector>
using namespace std;
int dp[1001][10001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];
  for (int i = 0; i < N; i++) {
    for (int j = w[i]; j <= W; j++) {
      dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
    }
  }
  cout << dp[N][W] << endl;
  return 0;
}