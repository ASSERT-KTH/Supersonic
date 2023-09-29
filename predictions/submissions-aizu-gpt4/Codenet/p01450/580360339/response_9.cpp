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
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  int cur = 0, nxt = 1;
  for (int i = 0; i < N; i++) {
    memcpy(dp[nxt], dp[cur], sizeof(dp[cur]));
    for (int j = 0; j + w[i] <= W; j++) {
      dp[nxt][j + w[i]] += dp[cur][j];
      if (dp[nxt][j + w[i]] >= mod)
        dp[nxt][j + w[i]] -= mod;
    }
    swap(cur, nxt);
  }
  ll ans = 0;
  for (int i = 0; i <= W; i++) {
    ans += dp[cur][i];
    if (ans >= mod)
      ans -= mod;
  }
  cout << ans << endl;
  return 0;
}