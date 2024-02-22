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
  for (int j = 0; j <= W; j++) {
    if (j <= W && (N == 0 || w[N - 1] + j > W))
      dp[N % 2][j] = 1;
    else
      dp[N % 2][j] = 0;
  }
  for (int i = N - 2; i >= 0; i--) {
    bool cur = (i + 1) % 2;
    bool nxt = i % 2;
    for (int j = 0; j <= W; j++) {
      dp[nxt][j] = 0;
      int nmwidx = i + 1;
      if (w[i + 1] > w[i])
        nmwidx = i;
      dp[nxt][j] = dp[cur][j] + (j + w[i] <= W ? dp[cur][j + w[i]] : 0);
      dp[nxt][j] %= mod;
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}