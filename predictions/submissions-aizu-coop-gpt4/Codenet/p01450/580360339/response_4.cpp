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

  // Initialize dp array
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;

  for (int i = 0; i < N; i++) {
    int cur = i % 2;
    int nxt = 1 - cur;
    memcpy(dp[nxt], dp[cur], sizeof(dp[cur]));
    for (int j = 0; j <= W - w[i]; j++) {
        dp[nxt][j + w[i]] += dp[cur][j];
        dp[nxt][j + w[i]] %= mod;
    }
  }
  ll sum = 0;
  for (int i = 0; i <= W; i++) {
    sum += dp[N % 2][i];
    sum %= mod;
  }
  cout << sum << endl;
  return 0;
}