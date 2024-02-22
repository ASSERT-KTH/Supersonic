#include <algorithm>
#include <iostream>
#include <cstring>
#define ll long long
#define maxn 100009
#define inf 999999999999
using namespace std;
char s[25];
int num[105];
int main() {
  int n, m, x, y;
  while (cin >> n, n != 0) {
    for (int i = 0; i < n; i++)
      cin >> num[i];
    sort(num, num + n);
    ll dp1[10009] = {0}, dp2[10006] = {0};
    dp2[0] = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> s >> x >> s >> y;
      if (x == 0 && y > 0) {
        cout << "0" << endl;
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
    ll ans = 1ll << 60, sum, lb[105];
    for (int j = 0; j < n; j++)
      lb[j] = lower_bound(dp1, dp1 + 10000, num[j]) - dp1;
    for (int i = 0; i < 10001; i++) {
      if (dp2[i] < 0)
        continue;
      sum = i;
      for (int j = 0; j < n; j++)
        sum += lb[j] - dp2[i];
      ans = min(ans, sum);
    }
    cout << ans << endl;
  }
  return 0;
}