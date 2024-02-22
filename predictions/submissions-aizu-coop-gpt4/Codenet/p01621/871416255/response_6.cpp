#include <bits/stdc++.h>
using namespace std;
int s, n, t, m, p;
bitset<7 * 24 * 60> minutes;
int wbits, tbits;
double ck(int start) {
  int cnt = 0;
  int mod = 7 * 24 * 60;
  for (int i = 0, curMin = start % mod; i < m; i++, curMin = (curMin + t) % mod) {
    bool flag = true;
    for (int j = 0, curJ = curMin; j <= s; j++, curJ = (curJ + 1) % mod) {
      if (!minutes[curJ]) {
        flag = false;
        break;
      }
    }
    cnt += flag;
  }
  return (1.0 - pow(1.0 - 1.0 / p, (double)cnt * n));
}
inline int todays(int i) { return (i / (24 * 60)); }
inline bool totime(int i) {
  int tm = i % (24 * 60) / 24;
  return (tm >= 18 || tm < 6);
}
int main() {
  string weekday, time;
  while (cin >> s >> n >> t >> weekday >> time >> p >> m, m) {
    if (weekday == "All")
      wbits = (1 << 7) - 1;
    else
      wbits = 1;
    if (time == "Night")
      tbits = 1;
    else if (time == "Day")
      tbits = 2;
    else
      tbits = 3;
    double ans = 0.0;
    minutes.reset();
    for (int i = 7 * 24 * 60 - 1; i >= 0; i--) {
      if ((wbits & (1 << i / 1440)) && (tbits & (1 << ((i / 360 + 1) % 4 / 2))))
        minutes[i] = 1;
    }
    for (int i = 24 * 60 - 1; i >= 0; i--) {
      ans = max(ans, ck(i));
    }
    cout << fixed << setprecision(16) << ans << endl;
  }
}