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
    for (int k = 0; k <= N; k++) {
      if (j == 0)
        dp[N % 2][j][k] = 1;
      else if (k == N)
        dp[N % 2][j][k] = 0;
      else {
        int nmwidx = k + 1;
        if (w[k] > j)
          nmwidx = k;
        dp[N % 2][j][k] = dp[N % 2][j][k + 1];
        dp[N % 2][j][k] += dp[N % 2][j - w[k]][k];
        dp[N % 2][j][k] %= mod;
      }
    }
  }
  for (int i = N - 2; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j <= W; j++) {
      for (int k = 0; k <= N; k++) {
        if (k == N)
          dp[nxt][j][k] = 0;
        else if (w[i] > j)
          dp[nxt][j][k] = dp[cur][j][k + 1];
        else {
          int nmwidx = k + 1;
          if (w[k] > w[i])
            nmwidx = i;
          dp[nxt][j][k] = dp[cur][j][nmwidx];
          dp[nxt][j][k] += dp[cur][j - w[i]][k + 1];
          dp[nxt][j][k] %= mod;
        }
      }
    }
  }
  cout << dp[0][W][0] << endl;
  return 0;
}