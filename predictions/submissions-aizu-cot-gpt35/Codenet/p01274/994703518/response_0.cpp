#include <algorithm>
#include <cstdio>
#include <cstring>

#define maxn 100009

using namespace std;

long long dp1[10009];
long long dp2[10006];
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
      dp2[i] = -1000000000000LL;

    dp2[0] = 0;

    scanf("%d", &m);

    int index = 0;

    for (int i = 0; i < m; i++) {
      scanf("%s", s);
      scanf("%d", &x);
      scanf("%s", s);
      scanf("%d", &y);

      if (x == 0 && y > 0) {
        printf("0\n");
        continue;
      }

      if (s[0] == 'S') {
        for (int j = x; j <= 10000; j++)
          dp1[j] = max(dp1[j], dp1[j - x] + y);
      } else {
        for (int j = x; j <= 10000; j++)
          dp2[j] = max(dp2[j], dp2[j - x] + y);
      }
    }

    long long ans = 1ll << 60;
    long long sum;

    for (int i = 0; i < 10001; i++) {
      if (dp2[i] < 0)
        continue;

      sum = i;

      for (int j = 0; j < n; j++) {
        while (index < 10000 && dp1[index] < num[j] - dp2[i])
          index++;

        sum += index;
      }

      ans = min(ans, sum);
    }

    printf("%lld\n", ans);
  }

  return 0;
}