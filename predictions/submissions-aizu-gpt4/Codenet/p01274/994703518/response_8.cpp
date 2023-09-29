#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
#define maxn 100009
#define inf 999999999999
using namespace std;
ll dp[2][10009];
int num[105];
int main() {
  int n, m, x, y;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);
    sort(num, num + n);
    memset(dp, 0, sizeof dp);
    dp[1][0] = -inf;
    scanf("%d", &m);
    bool flag = 0;
    for (int i = 0; i < m; i++) {
      char s[25];
      scanf("%s", s);
      scanf("%d", &x);
      scanf("%s", s);
      scanf("%d", &y);
      if (x == 0 && y > 0)
        flag = 1;
      int idx = (s[0] == 'S') ? 0 : 1;
      for (int j = x; j <= 10000; j++)
        dp[idx][j] = max(dp[idx][j], dp[idx][j - x] + y);
    }
    if (flag) {
      puts("0");
      continue;
    }
    ll ans = 1ll << 60, sum;
    for (int i = 0; i < 10001; i++) {
      if (dp[1][i] < 0)
        continue;
      sum = i;
      for (int j = 0; j < n; j++) {
        sum += lower_bound(dp[0], dp[0] + 10001, num[j] - dp[1][i]) - dp[0];
      }
      ans = min(ans, sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}