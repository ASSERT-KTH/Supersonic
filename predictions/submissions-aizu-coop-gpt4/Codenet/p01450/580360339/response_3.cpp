#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[2][202];
int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];
  for (int j = 0; j <= W; j++) {
    if (j <= W)
      dp[N % 2][N] = 1;
    else
      dp[N % 2][N] = 0;
  }
  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j <= W; j++) {
      for (int k = 0; k <= N; k++) {
        if (w[k] > w[i]) break; // loop optimization
        dp[nxt][k] = 0;
        int nmwidx = k;
        if (k == N || w[k] > w[i])
          nmwidx = i;
        dp[nxt][k] += dp[cur][nmwidx];
        if (j + w[i] <= W)
          dp[nxt][k] += dp[cur][j + w[i]];
        if (dp[nxt][k] >= mod) // avoid modulus operation
          dp[nxt][k] %= mod;
      }
    }
  }
  cout << dp[0][N] << endl;
  return 0;
}