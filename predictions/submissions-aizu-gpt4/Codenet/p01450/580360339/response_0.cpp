#include <algorithm>
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
  sort(w, w + N);
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    int cur = i % 2;
    int nxt = 1 - cur;
    for (int j = 0; j <= W; j++)
      dp[nxt][j] = dp[cur][j];
    for (int j = 0; j <= W - w[i]; j++)
      dp[nxt][j + w[i]] = (dp[nxt][j + w[i]] + dp[cur][j]) % mod;
  }
  ll ans = 0;
  for (int i = 0; i <= W; i++)
    ans = (ans + dp[N % 2][i]) % mod;
  cout << ans << endl;
  return 0;
}