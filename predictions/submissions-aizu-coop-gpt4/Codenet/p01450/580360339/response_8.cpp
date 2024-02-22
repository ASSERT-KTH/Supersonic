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
  for (int j = 0; j <= W; j++)
    dp[N % 2][j] = 1;
  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j <= W; j++) {
      dp[nxt][j] = dp[cur][j];
      if (j + w[i] <= W)
        dp[nxt][j + w[i]] += dp[cur][j];
    }
    for (int j = 0; j <= W; j++)
      dp[nxt][j] %= mod;
  }
  cout << dp[0][W] << endl;
  return 0;
}