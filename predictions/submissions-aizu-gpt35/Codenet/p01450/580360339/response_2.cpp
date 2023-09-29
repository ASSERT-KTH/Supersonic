#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int MAX_N = 201;
const int MAX_W = 10001;

int N, W;
int w[MAX_N];
ll dp[2][MAX_W][MAX_N];

int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];
  memset(dp, 0, sizeof(dp));
  for (int j = 0; j <= W; j++) {
    dp[N % 2][j][N] = 1;
  }
  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j <= W; j++) {
      for (int k = 0; k <= N; k++) {
        dp[nxt][j][k] = 0;
        if (j + w[i] <= W)
          dp[nxt][j][k] += dp[cur][j + w[i]][i + 1];
        dp[nxt][j][k] += dp[cur][j][i + 1];
        dp[nxt][j][k] %= mod;
      }
    }
  }
  cout << dp[0][0][0] << endl;
  return 0;
}
