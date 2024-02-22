#include <iostream>
#include <algorithm>
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
  while (cin >> n) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      cin >> num[i];
    // Removed unnecessary sort step
    for (int i = 1; i <= 10000; i++)
      dp2[i] = -inf;
    dp2[0] = 0;
    // Removed unnecessary memset step
    cin >> m;
    bool flag = 0;
    for (int i = 0; i < m; i++) {
      cin >> s;
      cin >> x;
      cin >> s;
      cin >> y;
      if (x == 0 && y > 0)
        flag = 1;
      if (s[0] == 'S') {
        for (int j = x; j <= 10000; j++)
          dp1[j] = max(dp1[j], dp1[j - x] + y);
      } else {
        for (int j = x; j <= 10000; j++)
          dp2[j] = max(dp2[j], dp2[j - x] + y);
      }
    }
    if (flag) {
      cout << "0" << endl;
      continue;
    }
    ll ans = 1ll << 60, sum;
    for (int i = 0; i < 10001; i++) {
      if (dp2[i] < 0)
        continue;
      sum = i;
      // Optimized inner loop condition
      int lower_bound_result = lower_bound(dp1, dp1 + 10000, num[0] - dp2[i]) - dp1;
      for (int j = 0; j < n; j++) {
        sum += lower_bound_result;
      }
      ans = min(ans, sum);
    }
    // Optimized output format
    cout << ans << endl;
  }
  return 0;
}