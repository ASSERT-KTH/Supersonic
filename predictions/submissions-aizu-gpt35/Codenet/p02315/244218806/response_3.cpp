#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 1001;
const int MAXW = 10001;
int dp[2][MAXW];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, W;
  cin >> N >> W;
  vector<int> v(N), w(N);
  for (int i = 0; i < N; i++)
    cin >> v[i] >> w[i];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      dp[(i + 1) & 1][j] = dp[i & 1][j];
      if (j >= w[i]) {
        dp[(i + 1) & 1][j] = max(dp[(i + 1) & 1][j], dp[i & 1][j - w[i]] + v[i]);
      }
    }
  }
  cout << dp[N & 1][W] << endl;
  return 0;
}