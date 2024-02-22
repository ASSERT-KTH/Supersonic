#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long
#define maxn 10009
#define inf 999999999999
using namespace std;

vector<ll> dp1(maxn);
vector<ll> dp2(maxn);
vector<int> num(maxn);
char s[25];

int main() {
  ios::sync_with_stdio(false); // faster I/O
  cin.tie(NULL); // untie cin and cout

  int n, m, x, y;

  while (cin >> n) {

    if (n == 0)
      return 0;

    for (int i = 0; i < n; i++)
      cin >> num[i];

    sort(num.begin(), num.begin() + n);

    fill(dp2.begin(), dp2.end(), -inf);
    dp2[0] = 0;
    fill(dp1.begin(), dp1.end(), 0);

    cin >> m;

    bool flag = 0;
    for (int i = 0; i < m; i++) {
      cin >> s >> x >> s >> y;
      if (x == 0 && y > 0)
        flag = 1;
      if (s[0] == 'S') {
        for (int j = x; j <= maxn; j++)
          dp1[j] = max(dp1[j], dp1[j - x] + y);
      } else {
        for (int j = x; j <= maxn; j++)
          dp2[j] = max(dp2[j], dp2[j - x] + y);
      }
    }

    if (flag) {
      cout << "0\n";
      continue;
    }

    ll ans = 1ll << 60, sum;
    for (int i = 0; i < maxn; i++) {
      if (dp2[i] < 0)
        continue;
      sum = i;
      for (int j = 0; j < n; j++) {
        ll tmp = num[j] - dp2[i]; // store the result of the computation
        sum += lower_bound(dp1.begin(), dp1.begin() + maxn, tmp) - dp1.begin();
      }
      ans = min(ans, sum);
    }
    cout << ans << "\n";
  }
  return 0;
}