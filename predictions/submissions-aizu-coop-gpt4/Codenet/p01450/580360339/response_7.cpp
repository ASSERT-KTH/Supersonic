#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int MAXN = 201;
const int MAXW = 10001;
int N, W;
int w[MAXN];
ll dp[2][MAXW];
int min_w_idx[MAXW];
int main() {
  scanf("%d %d", &N, &W);
  for (int i = 0; i < N; i++)
    scanf("%d", &w[i]);
  fill(min_w_idx, min_w_idx + MAXW, N); 
  for(int i = 0; i < N; i++) {
    min_w_idx[w[i]] = min(min_w_idx[w[i]], i);
  }
  dp[N % 2][0] = 1;
  for (int i = N - 1; i >= 0; i--) {
    int cur = (i + 1) % 2;
    int nxt = (i) % 2;
    for (int j = 0; j <= W; j++) {
      dp[nxt][j] = dp[cur][j];
      if (j >= w[i])
        dp[nxt][j] = (dp[nxt][j] + dp[cur][j - w[i]]) % mod;
    }
  }
  printf("%lld\n", dp[0][W]);
  return 0;
}