#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define ll long long
#define inf 999999999999
using namespace std;
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  vector<int> num(105);
  vector<ll> dp2(10006, -inf);
  map<int, ll> dp1;
  char s[25];
  int n, m, x, y;
  while (cin >> n && n != 0) {
    for (int i = 0; i < n; i++)
      cin >> num[i];
    sort(num.begin(), num.begin() + n);
    dp1.clear();
    dp2.assign(10006, -inf);
    dp2[0] = 0;
    cin >> m;
    bool flag = 0;
    for (int i = 0; i < m; i++) {
      cin >> s >> x >> s >> y;
      if (x == 0 && y > 0)
        flag = 1;
      auto& dp = (s[0] == 'S') ? dp1 : dp2;
      for (int j = x; j <= 10000; j++) {
        if (dp.count(j - x)) 
          dp[j] = max(dp[j], dp[j - x] + y);
      }
    }
    if (flag) {
      cout << "0" << "\n";
      continue;
    }
    ll ans = 1ll << 60, sum;
    for (int i = 0; i < 10001; i++) {
      if (dp2[i] < 0)
        continue;
      sum = i;
      for (int j = 0; j < n; j++) {
        auto it = dp1.lower_bound(num[j] - dp2[i]);
        if (it != dp1.end()) 
          sum += it->first;
      }
      ans = min(ans, sum);
    }
    cout << ans << "\n";
  }
  return 0;
}