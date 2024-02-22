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
  for (int j = 0; j <= N; j++) {
    if (j <= W)
      dp[N % 2][j] = 1;
    else
      dp[N % 2][j] = 0;
  }
  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j <= N; j++) {
      dp[nxt][j] = 0;
      int nmwidx = j;
      if (j == N || w[j] > w[i])
        nmwidx = i;
      dp[nxt][j] += dp[cur][nmwidx];
      if (j + w[i] <= W)
        dp[nxt][j] += dp[cur][j + w[i]];
      dp[nxt][j] %= mod;
    }
  }
  cout << dp[0][N] << endl;
  return 0;
}