#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[2][10001];
int main() {
  cin >> N >> W;
  for (int i = 0; i < N; i++)
    cin >> w[i];
  for (int j = 0; j <= W; j++) {
    dp[N % 2][j] = (j <= w[N - 1] && j <= W) ? 1 : 0;
  }
  for (int i = N - 2; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = i % 2;
    for (int j = 0; j <= W; j++) {
      dp[nxt][j] = 0;
      dp[nxt][j] += dp[cur][j];
      if (j + w[i] <= W)
        dp[nxt][j] += dp[cur][j + w[i]];
      dp[nxt][j] %= mod;
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}