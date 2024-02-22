#include <cstdio>
#include <algorithm>
#include <cstring>

#define maxn 100009

int dp1[10009];
int dp2[10006];
char s[25];
int num[105];

int main() {
  int n, m, x, y;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);
    std::sort(num, num + n);
    for (int i = 1; i <= 10005; i++)
      dp2[i] = -1e9;
    dp2[0] = 0;
    memset(dp1, 0, sizeof dp1);
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
        for (int j = x; j <= 10005; j++)
          dp1[j] = std::max(dp1[j], dp1[j - x] + y);
      } else {
        for (int j = x; j <= 10005; j++)
          dp2[j] = std::max(dp2[j], dp2[j - x] + y);
      }
    }
    if (flag) {
      puts("0");
      continue;
    }
    long long ans = 1LL << 60, sum;
    for (int i = 0; i < 10000; i++) {
      if (dp2[i] < 0)
        continue;
      sum = i;
      for (int j = 0; j < n; j++) {
        int k;
        for (k = 0; k < 10000; k++) {
          if (num[j] - dp2[i] <= dp1[k])
            break;
        }
        sum += k;
      }
      ans = std::min(ans, sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}