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
  scanf("%d%d", &N, &W);
  for (int i = 0; i < N; i++)
    scanf("%d", &w[i]);

  memset(dp[N % 2], 0, sizeof(ll) * (W + 1));
  for (int k = 0; k <= N; k++) {
    if (w[k] > W)
      dp[N % 2][k] = 1;
  }

  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = i % 2;
    for (int j = 0; j <= W; j++) {
      dp[nxt][j] = 0;
      int nmwidx = i;
      if (w[i] > w[N])
        nmwidx = N;
      dp[nxt][j] = (dp[nxt][j] + dp[cur][nmwidx]) % mod;
      if (j + w[i] <= W)
        dp[nxt][j] = (dp[nxt][j] + dp[cur][j + w[i]]) % mod;
    }
  }

  printf("%lld\n", dp[0][0]);
  return 0;
}