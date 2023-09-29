#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 100009
#define inf 999999999999
using namespace std;
ll dp1[10009];
ll dp2[10006];
int num[105];
int main() {
  int n, m, x, y;
  ios_base::sync_with_stdio(false); cin.tie(NULL); // Improves IO speed
  while (cin >> n) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      cin >> num[i];
    sort(num, num + n);
    fill(dp2, dp2 + 10001, -inf); // Replaced explicit loop with STL fill
    dp2[0] = 0;
    memset(dp1, 0, sizeof dp1);
    cin >> m;
    bool flag = 0;
    for (int i = 0; i < m; i++) {
      string s;
      cin >> s >> x >> s >> y;
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
      cout << "0\n";
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
    cout << ans << '\n';
  }
  return 0;
}