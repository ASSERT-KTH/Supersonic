#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
#define maxn 100009
#define inf 999999999999
using namespace std;

int num[105];
char s[25];

int main() {
  int n, m, x, y;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);
    sort(num, num + n);
    scanf("%d", &m);

    bool flag = 0;
    ll ans = 1ll << 60, sum;
    for (int i = 0; i < m; i++) {
      ll dp1[10009] = {0}; // Move dp1 declaration inside the loop
      scanf("%s", s);
      scanf("%d", &x);
      scanf("%s", s);
      scanf("%d", &y);
      if (x == 0 && y > 0)
        flag = 1;
      if (s[0] == 'S') {
        for (int j = x; j <= 10000; j++)
          dp1[j] = max(dp1[j], dp1[j - x] + y);
      } else {
        ll dp2[10006]; // Initialize dp2 once outside the loop
        memset(dp2, -inf, sizeof(dp2));
        dp2[0] = 0;
        for (int j = x; j <= 10000; j++)
          dp2[j] = max(dp2[j], dp2[j - x] + y);
      }
      if (flag) {
        puts("0");
        continue;
      }
      for (int i = 0; i < 10001; i++) {
        if (dp2[i] < 0)
          continue;
        sum = i;
        for (int j = 0; j < n; j++) {
          int pos = 0;
          while (pos < 10000 && dp1[pos] < num[j] - dp2[i]) {
            pos++;
          }
          sum += pos;
        }
        ans = min(ans, sum);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}