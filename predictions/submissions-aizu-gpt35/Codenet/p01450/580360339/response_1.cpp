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
  for (int j = 0; j <= W; j++) {
    for (int k = 0; k <= N; k++) {
      if (j == 0) dp[N % 2][0][k] = 1;
      else if (k == N) dp[N % 2][j][k] = 0;
      else {
        dp[N % 2][j][k] = dp[N % 2][j][k + 1];
        if (j >= w[k]) dp[N % 2][j][k] = (dp[N % 2][j][k] + dp[N % 2][j - w[k]][k + 1]) % mod;
      }
    }
  }
  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j <= W; j++) {
      for (int k = 0; k <= N; k++) {
        dp[nxt][j][k] = 0;
        if (k == N) dp[nxt][j][k] = dp[cur][j][k];
        else {
          dp[nxt][j][k] = dp[cur][j][k + 1];
          if (j + w[i] <= W) dp[nxt][j][k] = (dp[nxt][j][k] + dp[cur][j + w[i]][k + 1]) % mod;
        }
      }
    }
  }
  cout << dp[0][0][0] << endl;
  return 0;
}