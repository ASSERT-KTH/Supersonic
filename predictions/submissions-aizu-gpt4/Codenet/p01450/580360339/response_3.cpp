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
  dp[N % 2][0] = 1;
  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j <= W; j++) {
      dp[nxt][j] = dp[cur][j];
      if (j + w[i] <= W)
        dp[nxt][j + w[i]] += dp[cur][j];
      dp[nxt][j] %= mod;
      if (j + w[i] <= W)
        dp[nxt][j + w[i]] %= mod;
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}