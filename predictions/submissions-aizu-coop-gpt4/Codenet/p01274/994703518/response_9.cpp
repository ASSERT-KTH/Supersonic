#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#define ll long long
#define maxn 100009
#define inf 999999999999
using namespace std;
map<ll, ll> dp1;
map<ll, ll> dp2;
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
    dp2.clear();
    dp2[0] = 0;
    dp1.clear();
    scanf("%d", &m);
    bool flag = 0;
    for (int i = 0; i < m; i++) {
      scanf("%s", s);
      scanf("%d", &x);
      scanf("%s", s);
      scanf("%d", &y);
      if (x == 0 && y > 0)
        flag = 1;
      ll val = (s[0] == 'S') ? dp1[x] + y : dp2[x] + y;
      for (int j = x; j <= 10000; j++)
        if (s[0] == 'S')
          dp1[j] = max(dp1[j], val);
        else
          dp2[j] = max(dp2[j], val);
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
        sum += lower_bound(dp1.begin(), dp1.end(), num[j] - dp2[i]) - dp1.begin();
      }
      ans = min(ans, sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}