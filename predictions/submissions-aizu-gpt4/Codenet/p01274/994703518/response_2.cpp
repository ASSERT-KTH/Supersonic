#include <cstdio>
#include <algorithm>
#define ll long long
#define maxn 100009
#define inf 999999999999
ll dp1[10009];
ll dp2[10006];
int num[105];
int main() {
  int n, m, x, y;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);
    std::sort(num, num + n);
    std::fill(dp2, dp2 + 10006, -inf);
    dp2[0] = 0;
    std::fill(dp1, dp1 + 10009, 0);
    scanf("%d", &m);
    bool flag = 0;
    while(m--){
      char s;
      scanf(" %c%d %c%d", &s, &x, &s, &y);
      if (x == 0 && y > 0)
        flag = 1;
      ll* dp = s == 'S' ? dp1 : dp2;
      for (int j = x; j <= 10000; j++)
        dp[j] = std::max(dp[j], dp[j - x] + y);
    }
    if (flag) {
      puts("0");
      continue;
    }
    ll ans = 1ll << 60, sum;
    for (int i = 0; i < 10001; i++) {
      if (dp2[i] < 0)
        continue;
      sum = i;
      for (int j = 0; j < n; j++) {
        sum += std::lower_bound(dp1, dp1 + 10000, num[j] - dp2[i]) - dp1;
      }
      ans = std::min(ans, sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}