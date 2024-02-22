#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
#define maxn 10001
#define inf 999999999999
using namespace std;
ll dp1[10001];
ll dp2[10001];
char s[25];
int num[10001];
int main() {
  int n, m, x, y;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);
    for (int i = 1; i <= 10000; i++)
      dp2[i] = -inf;
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
        for (int j = x; j <= 10000; j += x)
          dp1[j] = max(dp1[j], dp1[j - x] + y);
      } else {
        for (int j = x; j <= 10000; j += x)
          dp2[j] = max(dp2[j], dp2[j - x] + y);
      }
    }
    if (flag) {
      puts("0");
      continue;
    }
    ll ans = 1ll << 60, sum;
    for (int i = 0; i < maxn; i++) {
      if (dp2[i] < 0)
        continue;
      sum = i;
      for (int j = 0; j < n; j++) {
        sum += lower_bound(dp1, dp1 + maxn, num[j] - dp2[i]) - dp1;
      }
      ans = min(ans, sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}