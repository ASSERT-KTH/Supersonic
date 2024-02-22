#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[2][10001][202];
int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];
  for (int j = 0; j <= W; j++) {
    for (int k = 0; k < N; k++) {
      if (j <= W && (k == N - 1 || w[k] + j > W))
        dp[N % 2][j][k] = 1;
      else
        dp[N % 2][j][k] = 0;
    }
  }
  for (int i = N - 2; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j <= W; j++) {
      dp[nxt][j][N - 1] = dp[cur][j][i];
      if (j + w[i] <= W)
        dp[nxt][j][i] = (dp[cur][j][i] + dp[cur][j + w[i]][N - 1]) % mod;
      else
        dp[nxt][j][i] = dp[cur][j][i];
    }
  }
  cout << dp[0][0][0] << endl;
  return 0;
}