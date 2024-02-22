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
    for (int i = 1; i <= 10000; i++)
      dp2[i] = -inf;
    dp2[0] = 0;
    memset(dp1, 0, sizeof dp1);
    scanf("%d", &m);
    bool flag = 0;
    ll temp1[10001], temp2[10001]; //temporary arrays to store intermediate computations
    for (int i = 0; i < m; i++) {
      scanf("%s", s);
      scanf("%d", &x);
      scanf("%s", s);
      scanf("%d", &y);
      if (x == 0 && y > 0)
        flag = 1;
      for (int j = x; j <= 10000; j++) {
         temp1[j] = dp1[j - x] + y; //store intermediate computation in temporary array
         temp2[j] = dp2[j - x] + y; //store intermediate computation in temporary array
      }
      if (s[0] == 'S') {
        for (int j = x; j <= 10000; j++)
          dp1[j] = max(dp1[j], temp1[j]); //use temporary array
      } else {
        for (int j = x; j <= 10000; j++)
          dp2[j] = max(dp2[j], temp2[j]); //use temporary array
      }
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
        int l = 0, r = 10000, mid;
        while (l <= r) { //binary search
           mid = (l + r) / 2;
           if (dp1[mid] < num[j] - dp2[i])
              l = mid + 1;
           else
              r = mid - 1;
        }
        sum += l;
      }
      ans = min(ans, sum);
    }
    printf("%lld\n", ans);
  }
  return 0;
}