#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define inf 999999999999
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, x, y;
  while (cin >> n) {
    if (n == 0) break;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
      cin >> num[i];
    sort(num.begin(), num.end());
    vector<ll> dp1(10001, 0), dp2(10001, -inf);
    dp2[0] = 0;
    cin >> m;
    for (int i = 0; i < m; i++) {
      string s;
      cin >> s >> x >> s >> y;
      if (x == 0 && y > 0) {
        cout << "0\n";
        break;
      }
      if (s[0] == 'S') {
        for (int j = x; j <= 10000; j++)
          dp1[j] = max(dp1[j], dp1[j - x] + y);
      } else {
        for (int j = x; j <= 10000; j++)
          dp2[j] = max(dp2[j], dp2[j - x] + y);
      }
    }
    ll ans = 1ll << 60, sum;
    for (int i = 0; i < 10001; i++) {
      if (dp2[i] < 0) continue;
      sum = i;
      for (int j = 0; j < n; j++) {
        ll temp = lower_bound(dp1.begin(), dp1.end(), num[j] - dp2[i]) - dp1.begin();
        sum += temp;
      }
      ans = min(ans, sum);
    }
    cout << ans << "\n";
  }
  return 0;
}