#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define ll long long
#define inf 999999999999
using namespace std;
vector<ll> dp1(10009, 0);
vector<ll> dp2(10006, -inf);
char s[25];
vector<int> num(105);
int main() {
  int n, m, x, y, maxIdx = 0;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);
    sort(num.begin(), num.begin() + n);
    dp2.assign(10006, -inf);
    dp2[0] = 0;
    dp1.assign(10009, 0);
    scanf("%d", &m);
    bool flag = 0;
    for (int i = 0; i < m; i++) {
      scanf("%s", s);
      scanf("%d", &x);
      scanf("%s", s);
      scanf("%d", &y);
      if (x == 0 && y > 0)
        flag = 1;
      if (s[0] == 'S') {
        for (int j = x; j <= maxIdx; j++)
          dp1[j] = max(dp1[j], dp1[j - x] + y);
        maxIdx = max(maxIdx, x);
      } else {
        for (int j = x; j <= maxIdx; j++)
          dp2[j] = max(dp2[j], dp2[j - x] + y);
        maxIdx = max(maxIdx, x);
      }
    }
    if (flag) {
      puts("0");
      continue;
    }
    ll ans = 1ll << 60, sum;
    auto it = dp1.begin();
    #pragma omp parallel for
    for (int i = 0; i <= maxIdx; i++) {
      if (dp2[i] < 0)
        continue;
      sum = i;
      for (int j = 0; j < n; j++) {
        it = lower_bound(it, dp1.end(), num[j] - dp2[i]);
        sum += it - dp1.begin();
      }
      #pragma omp critical
      {
        ans = min(ans, sum);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}