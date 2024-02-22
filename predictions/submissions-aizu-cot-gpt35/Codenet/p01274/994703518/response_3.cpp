#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n, m, x, y;
  while (cin >> n) {
    if (n == 0)
      break;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
      cin >> num[i];
    sort(num.begin(), num.end());

    vector<int> dp1(10009);
    vector<int> dp2(10006, -1e9);
    dp2[0] = 0;

    cin >> m;
    bool flag = false;
    for (int i = 0; i < m; i++) {
      string s;
      cin >> s;
      cin >> x;
      cin >> s;
      cin >> y;
      if (x == 0 && y > 0)
        flag = true;
      if (s[0] == 'S') {
        for (int j = x; j <= 10000; j++)
          dp1[j] = max(dp1[j], dp1[j - x] + y);
      } else {
        for (int j = x; j <= 10000; j++)
          dp2[j] = max(dp2[j], dp2[j - x] + y);
      }
    }

    if (flag) {
      cout << 0 << endl;
      continue;
    }

    long long ans = 1ll << 60, sum;
    for (int i = 0; i < 10001; i++) {
      if (dp2[i] < 0)
        continue;
      sum = i;
      for (int j = 0; j < n; j++) {
        sum += lower_bound(dp1.begin(), dp1.end(), num[j] - dp2[i]) - dp1.begin();
      }
      ans = min(ans, sum);
    }

    cout << ans << endl;
  }
  return 0;
}