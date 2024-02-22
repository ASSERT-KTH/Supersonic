#include <cstdio>
#include <vector>
#define ll long long

int main() {
  int n, m, x, y;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    
    std::vector<int> num(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);

    scanf("%d", &m);
    bool flag = false;

    std::vector<ll> dp1(10009, 0);
    std::vector<ll> dp2(10006, -1e18);

    dp2[0] = 0;

    for (int i = 0; i < m; i++) {
      char s[25];
      scanf("%s%d%s%d", s, &x, s, &y);
      if (x == 0 && y > 0)
        flag = true;

      if (s[0] == 'S') {
        for (int j = 10000; j >= x; j--)
          dp1[j] = std::max(dp1[j], dp1[j - x] + y);
      } else {
        for (int j = 10000; j >= x; j--)
          dp2[j] = std::max(dp2[j], dp2[j - x] + y);
      }
    }

    if (flag) {
      puts("0");
      continue;
    }

    ll ans = 1LL << 60;
    ll sum = 0;

    for (int i = 10000; i >= 0; i--) {
      if (dp2[i] >= 0) {
        for (int j = 0; j < n; j++) {
          sum += std::lower_bound(dp1.begin(), dp1.end(), num[j] - dp2[i]) - dp1.begin();
        }
        ans = std::min(ans, sum + i);
      }
    }

    printf("%lld\n", ans);
  }

  return 0;
}