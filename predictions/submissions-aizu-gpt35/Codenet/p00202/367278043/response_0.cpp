#include <algorithm>
#include <cstdio>
using namespace std;
constexpr int MAXN = 30;
constexpr int MAXX = 1000000;
int n, x, a[MAXN];
bool dp[MAXX+1], prime[MAXX+1];
int main() {
  prime[0] = prime[1] = true;
  for (int i = 4; i <= MAXX; i += 2) prime[i] = true;
  for (int i = 3; i * i <= MAXX; i += 2)
    if (!prime[i])
      for (int j = i * i; j <= MAXX; j += 2 * i)
        prime[j] = true;
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    fill(dp, dp + x + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; ++i)
      for (int j = a[i]; j <= x; ++j)
        dp[j] |= dp[j - a[i]];
    int ans = -1;
    for (int i = x; i > 0; --i)
      if (dp[i] && !prime[i]) {
        ans = i;
        break;
      }
    printf("%d\n", ans);
  }
}