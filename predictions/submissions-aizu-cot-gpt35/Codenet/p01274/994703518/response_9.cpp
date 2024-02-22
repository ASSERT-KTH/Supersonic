#include <cstdio>
#include <climits>
#define ll long long
#define maxn 100009

ll dp1[maxn];
ll dp2[maxn];
char s[25];
int num[maxn];

int main() {
  int n, m, x, y;

  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;

    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);

    std::sort(num, num + n);

    for (int i = 1; i <= maxn; i++)
      dp2[i] = -INT_MAX;
    dp2[0] = 0;

    scanf("%d", &m);

    bool flag = false;
    for (int i = 0; i < m; i++) {
      scanf("%s", s);
      scanf("%d", &x);
      scanf("%s", s);
      scanf("%d", &y);

      if (x == 0 && y > 0)
        flag = true;

      if (s[0] == 'S') {
        for (int j = x; j <= maxn; j++)
          dp1[j] = std::max(dp1[j], dp1[j - x] + y);
      } else {
        for (int j = x; j <= maxn; j++)
          dp2[j] = std::max(dp2[j], dp2[j - x] + y);
      }
    }

    if (flag) {
      puts("0");
      continue;
    }

    ll ans = 1ll << 60, sum;
    for (int i = 0; i <= maxn; i++) {
      if (dp2[i] < 0)
        continue;

      sum = i;
      for (int j = 0; j < n; j++) {
        sum += std::lower_bound(dp1, dp1 + maxn, num[j] - dp2[i]) - dp1;
      }

      ans = std::min(ans, sum);
    }

    printf("%lld\n", ans);
  }

  return 0;
}