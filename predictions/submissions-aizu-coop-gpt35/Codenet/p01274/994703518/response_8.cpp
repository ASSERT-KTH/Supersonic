#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
#define maxn 10001
#define inf 999999999999
using namespace std;
ll dp1[maxn];
ll dp2[maxn];
char s[25];
int num[105];

int main() {
  int n, m, x, y;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);
    sort(num, num + n);
    for (int i = 1; i <= 10000; i++)
      dp2[i] = -inf;
    dp2[0] = 0;
    memset(dp1, 0, sizeof dp1);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      scanf("%s", s);
      scanf("%d", &x);
      scanf("%s", s);
      scanf("%d", &y);
      for (int j = x; j <= 10000; j++) {
        if (s[0] == 'S') {
          dp1[j] = max(dp1[j], dp1[j - x] + y);
        } else {
          dp2[j] = max(dp2[j], dp2[j - x] + y);
        }
      }
    }
    ll ans = 1ll << 60, sum;
    for (int i = 0; i <= 10000; i++) {
      if (dp2[i] < 0)
        continue;
      sum = i;
      for (int j = 0; j < n; j++) {
        sum += lower_bound(dp1, dp1 + 10000, num[j] - dp2[i]) - dp1;
      }
      ans = min(ans, sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}