#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define maxn 100009
#define inf 999999999999
using namespace std;
vector<ll> dp1(10009);
vector<ll> dp2(10006);
char s[25];
vector<int> num(105);
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n, m, x, y;
  while (cin >> n) {
    if (n == 0)
      break;
    for (int i = 0; i < n; i++)
      cin >> num[i];
    sort(num.begin(), num.end());
    fill(dp2.begin(), dp2.end(), -inf);
    dp2[0] = 0;
    fill(dp1.begin(), dp1.end(), 0);
    cin >> m;
    bool flag = 0;
    for (int i = 0; i < m; i++) {
      cin >> s >> x >> s >> y;
      if (x == 0 && y > 0)
        flag = 1;
      ll max_val = 0;
      if (s[0] == 'S') {
        for (int j = x; j <= 10000; j++){
          max_val = max(max_val, dp1[j - x] + y);
          dp1[j] = max(dp1[j], max_val);
        }
      } else {
        for (int j = x; j <= 10000; j++){
          max_val = max(max_val, dp2[j - x] + y);
          dp2[j] = max(dp2[j], max_val);
        }
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
        sum += lower_bound(dp1.begin(), dp1.end() - 1, num[j] - dp2[i]) - dp1.begin();
      }
      ans = min(ans, sum);
    }
    cout << ans << "\n";
  }
  return 0;
}