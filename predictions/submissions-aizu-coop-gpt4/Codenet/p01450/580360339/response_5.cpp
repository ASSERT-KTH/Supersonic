#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int N, W;
int w[201];
ll dp[2][10001];
int min_w[10001];
int main() {
  scanf("%d %d", &N, &W);
  for (int i = 0; i < N; i++)
    scanf("%d", &w[i]);
  for (int j = 0; j <= W; j++) {
    if (j <= W)
      dp[N % 2][j] = 1;
    else
      dp[N % 2][j] = 0;
  }
  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j <= W; j++) {
      dp[nxt][j] = dp[cur][j];
      int nmwidx = min_w[j];
      if (nmwidx == N || w[nmwidx] > w[i])
        nmwidx = i;
      if (j + w[i] <= W)
        dp[nxt][j] += dp[cur][j + w[i]];
      dp[nxt][j] %= mod;
      min_w[j] = nmwidx;
    }
  }
  printf("%lld\n", dp[0][0]);
  return 0;
}