#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[2][10001][2];
int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];
  for (int j = 0; j <= W; j++) {
    for (int k = 0; k <= 1; k++) {
      dp[N % 2][j][k] = (k == 0);
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j <= W; j++) {
      dp[nxt][j][0] = dp[cur][j][0];
      if (j + w[i] <= W)
        dp[nxt][j][0] = (dp[nxt][j][0] + dp[cur][j + w[i]][1]) % mod;
      dp[nxt][j][1] = dp[cur][j][1];
      if (j + w[i] <= W)
        dp[nxt][j][1] = (dp[nxt][j][1] + dp[cur][j + w[i]][0]) % mod;
    }
  }
  cout << dp[0][0][1] << endl;
  return 0;
}