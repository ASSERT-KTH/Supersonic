#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
#define maxn 100009
#define inf 999999999999
using namespace std;
ll dp1[10009];
ll dp2[10006];
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
    fill(dp2+1, dp2+10006, -inf);
    dp2[0] = 0;
    memset(dp1, 0, sizeof dp1);
    scanf("%d", &m);
    bool flag = 0;
    while(m--){
      scanf("%s%d%s%d", s, &x, s, &y);
      if (x == 0 && y > 0)
        flag = 1;
      for (int j = x; j <= 10000; j++)
        if (s[0] == 'S')
          dp1[j] = max(dp1[j], dp1[j - x] + y);
        else
          dp2[j] = max(dp2[j], dp2[j - x] + y);
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
        sum += lower_bound(dp1, dp1 + 10000, num[j] - dp2[i]) - dp1;
      }
      ans = min(ans, sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}